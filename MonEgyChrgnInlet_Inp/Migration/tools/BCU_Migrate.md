# TPT TO BCU Migration Guide

## Overview

This guide provides a standardized process for migrating Test Platform TPT scripts to BCU-compatible implementations. It covers script extraction, conversion steps, and best practices to ensure a smooth transition. All relevant functions are analyzed and ported from TPT assesslet scripts for BCU integration.

## Project Objective
1. [Migration Process](#migration-process)


## Migration Process

### Step 1: Script Extraction

- Analyze the .tpt files for function definitions.
- Extract functions from TPT assesslet_scripts.
- Create output files based on Conversion_Template.md in Phase 1.

### Step 2: python to C implementation
- Analyze the .py files and refer to Conversion_Template.md for python to c convertion.
- Convert the python functions to c function implementation.
- Create output files based on Conversion_Template.md in Phase 2.

#### Script Extraction Options:

##### 1. Master File Approach (Default)
- Extract all functions and save to a single comprehensive Python file.
- The master file name is automatically derived from the "FC under Test" attribute in the TPT file.
- This is the default behavior of extract_step1.py.
- Example: `python extract_step1.py`

##### 2. Individual Files Approach
- Extract each function into its own dedicated Python file.
- Each file follows the Conversion_Template.md format, including proper function header comments.
- Easier to maintain and review individual functions.
- Use `--individual` flag to generate individual files.
- Example: `python extract_step1.py --individual`

#### python to C implementation Options:

##### 1. Master File Approach (Default)
- Extract all functions and save to a single comprehensive .c and .h files.
- The master file name is automatically derived from the "FC under Test" attribute in the TPT file.
- This is the default Options for python to c convertion.
- Example: `Generate with Option1`

##### 2. Individual Files Approach
- Extract each function into its own dedicated .c and .h files.
- Each file follows the Conversion_Template.md format, including proper function header comments.
- Easier to maintain and review individual functions.
- Use `Options2` flag to generate individual files.
- Example: `Generate with Option2`

## File References for Script Extraction

- **Source Scripts:** Located in `Maindirectory/tauto/*.tpt`
- **Destination Scripts:** Saved in `Maindirectory/Script/`
  - Individual files: `Script/FunctionName.py`
  - Master file: `Script/FC_Name.py` (automatically derived from TPT file metadata)
- **Conversion Template:** [Conversion_Template.md](../Template/Conversion_Template.md)
- **Extraction Script:** `extract_step1.py`

## File References for python to C implementation
- **Source Scripts:** Located in `Maindirectory/Script/`
- **Destination .c,.h files:** Saved in `Maindirectory/CAsseslets/`
- **Conversion Template:** [Conversion_Template.md](../Template/Conversion_Template.md)
- **Conversion Rules:** [Conversion_Rules.md](../Template/Conversion_Rules.md)

## Project setup batch file Usage

# Navigate to the tools directory
cd C:\Users\far1cob\Workspace\L2\Demo\Migration_framework\Demo_use\Migration\tools

# Full path specification
bcu_migration_framework.bat C:\Projects\BCU_Migration\MyNewProject


## Extraction Script Usage

```bash
# Extract to a single master file (default)
python extract_step1.py

# Extract to individual files
python extract_step1.py --individual

# Specify custom output directory
python extract_step1.py --output custom_directory

# Specify custom TPT file
python extract_step1.py --tpt path/to/custom_file.tpt

# Clean generated files (removes .py from Script/ except __init__.py, and .c/.h from CAsseslets/)
python extract_step1.py --clean

# Combine options
python extract_step1.py --individual --output custom_directory
```
## python to C implementation Usage
```bash
# Prompt
Convert all Python files from Script/ directory to C implementation following Conversion_Template.md Phase 2 and Conversion_Rules.md: generate master .c, .h, files in CAsseslets/ directory.
```

## Example Workflow
# 1. Create new project
bcu_migration_framework.bat C:\MyProjects\ECU_Migration

# 2. Navigate to project
cd C:\MyProjects\ECU_Migration

# 3. Copy your TPT files to tauto/ directory
copy "C:\source\my_spec.tpt" tauto\

# 4. Extract TPT functions
cd Migration
python extract_step1.py

# 5. Review extracted Python files in Script/
dir ..\Script\

# 6. Convert to C using templates (AI-assisted process)
# Follow tools\BCU_Migrate.md guidelines