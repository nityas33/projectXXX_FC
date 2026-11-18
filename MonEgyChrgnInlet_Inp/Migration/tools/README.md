# BCU Testcase Migration Tools

This directory contains Python scripts to automate the migration of BCU test cases from the legacy format to the new format with data file handling.

## Files

- `BCU_Migrate.md` - Main migration guide and process documentation
- `bcu_migration_framework.bat` - Migration framework setup and execution script
- `bcu_testcase_migrator.py` - Main migration script
- `extract_step1.py` - TPT script extraction tool
- `test_migration.py` - Test script to verify migration functionality
- `BCU_testcase_update.md` - Documentation showing migration patterns

## Migration Patterns

The migration script applies the following transformations to BCU test cases:

1. **Add variable reset**: Inserts `Bcu_ResetVariables();` after `Bcu_Scheduler_Reset();`

2. **Add data file setup**: Creates data file handler and adds all signals:
   ```c
   Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TestCaseName.dat", DataFileFormatMdf);
   Bcu_DataFile_AddAllSignals(handleWriter);
   ```

3. **Update execution calls**: Changes `Bcu_Scheduler_ExecuteStep(i)` to `Bcu_Scheduler_ExecuteStep(currentTime * tpt_stepsize)`

4. **Add data logging**: Inserts `Bcu_DataFile_WriteRecord(handleWriter, currentTime);` in execution loops

5. **Move assertions**: Relocates `BCU_ASSERT_*` statements to the end of the test case

6. **Add cleanup**: Adds `Bcu_DataFile_Close(handleWriter);` at the end

## Usage

### Basic Migration

Migrate a single test file:
```bash
python bcu_testcase_migrator.py input_file.c
```

This creates `input_file_migrated.c` with the transformed test cases.

### Specify Output File

```bash
python bcu_testcase_migrator.py input_file.c output_file.c
```

### Verbose Output

```bash
python bcu_testcase_migrator.py -v input_file.c
```

### Test the Migration

Run the test suite to verify the migration works correctly:
```bash
python test_migration.py
```

## Example Migration

**Before (Input):**
```c
BCU_AUTO_TESTCASE(TC_URT_Test_Area_1__Check_of_Initialization_TC1_0_Ini)
{
    Bcu_Scheduler_Reset();
    // Call Ini Proc and wrong Initialization of CPL variables
    Mo_SyC_stSub=64;
    Bcu_SetPhysValue("MoFRelsMngtPtRels_bbLoc1Cpl", 254);
    BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MoFRelsMngtPtRels_bbLoc1Cpl"),255);
    tpt_stepsize =0.01;
    waitTime =0.01;
    for (i = currentTime; i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
    }
    currentTime = i;
}
```

**After (Output):**
```c
BCU_AUTO_TESTCASE(TC_URT_Test_Area_1__Check_of_Initialization_TC1_0_Ini)
{
    Bcu_Scheduler_Reset();
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_URT_Test_Area_1__Check_of_Initialization_TC1_0_Ini.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
    
    // Call Ini Proc and wrong Initialization of CPL variables
    Mo_SyC_stSub=64;
    Bcu_SetPhysValue("MoFRelsMngtPtRels_bbLoc1Cpl", 254);
    tpt_stepsize =0.01;
    waitTime =0.01;
    for (i = currentTime; i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(currentTime * tpt_stepsize);
        Bcu_DataFile_WriteRecord(handleWriter, currentTime);
    }
    currentTime = i;
    
    BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MoFRelsMngtPtRels_bbLoc1Cpl"),255);
    
    Bcu_DataFile_Close(handleWriter);
}
```

## Target Files

This script is typically used to migrate test files such as:
- `My/my_testcases.c`
- Test files in the `Migration/CAsseslets/` directory
- Any C files containing `BCU_AUTO_TESTCASE` macros

## Requirements

- Python 3.6 or higher
- No external dependencies (uses only standard library)

## Error Handling

The script includes error handling for:
- Missing input files
- Invalid test case formats
- Regex matching failures
- File I/O errors

Warnings are displayed for test cases that cannot be migrated, but the script continues processing other test cases in the file.

## Limitations

- The script uses regex-based parsing, so very complex nested structures might not be handled perfectly
- Manual review of migrated code is recommended
- Some edge cases in code formatting might require manual adjustment

## Integration with BCU Migration Framework

This tool is part of the broader BCU Migration Framework and should be used in conjunction with other migration tools and documentation in the `Migration/` directory.
