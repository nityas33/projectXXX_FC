# Python to C Conversion Rules

This document provides a standardized approach for converting target languages (Python and C/C++).

## 1. CONVERSION RULES

### 1.1 Function Signature Conversion Rules

**RULE 1: Direct Parameter Mapping**
- C functions should use direct parameter mapping from Python functions
- Avoid complex input/output structures with pointers
- Use the same parameter names and types as Python implementation
- C function signatures must match Python function parameters exactly

**RULE 2: No Pointer Parameters for Inputs/Outputs**
- Input parameters should be passed by value, not by pointer
- Output values should be returned directly, not via output pointers
- Example: `bool T15Cond(bool flgT15)` instead of `bool T15Cond_Calculate(const T15Cond_Input_t* inputs, T15Cond_Output_t* outputs)`
- NO struct-based input/output parameters allowed

**RULE 3: Direct Return Values**
- Functions should return the computed result directly
- Avoid output structures and pointer parameters for simple return values
- Example: `return flgT15Cond;` instead of `outputs->flgT15Cond = result;`
- Single function output should be returned as function return value

**RULE 4: Use Native Types & Unified Selector Functions**
- Use native C data types (bool, int, float) instead of custom enums/structs
- if multiple Python outputs are derived from the same logic, implement a single C function with a selector parameter (e.g., const char* TYPE) to handle all cases.
- Output wrapper functions should call the unified function with the appropriate selector.
- Do not use `uint8_t`, `uint32_t`, or other fixed-width integer types for general logic or output values. Use `bool`, `int`, or `float` unless hardware or protocol requirements demand otherwise.

**RULE 5: One-to-One Function Mapping**
- Map each Python function to a corresponding C function.
- If the Python function uses a selector or returns multiple outputs, consolidate into one C function with a selector parameter.
- Output wrappers must match the Python output names and call the unified function with the correct selector.
- Ensure parameter order and types match between Python and C.

**RULE 6: Datatype Reference**
- Datatypes should be referenced from the project-specific stub files:
  - Use datatypes defined in `My\my_pavast_stubs.h` and `My\my_stubs.h`
  - Standard datatypes include: `bool`, `uint8`, `uint16`, `uint32`, `sint16`
  - Include appropriate headers: `my_pavast_stubs.h` and `my_stubs.h` for datatype definitions
  - Follow the existing project's datatype conventions rather than standard C types
  - DO NOT use standard C types like `uint8_t`, `int16_t`, `stdint.h` types
  - Use project-specific types: `uint8`, `uint16`, `uint32`, `sint16`, `sint32`

**RULE 7: File and Function Naming Consistency**
- Python file names should match C file names (both .c and .h)
- Function names should be consistent between Python and C implementations
- Update function signatures when implementation changes
- Validate that all listed functions have corresponding Python and C implementations
- Fix typos and ensure consistency with file names
- File structure should follow the pattern:
  - Python: `Script/Filename.py`
  - C Source: `CAsseslets/assesslets.c`
  - C Header: `CAsseslets/assesslets.h`
- Example: `def T15Cond(_flgT15, TYPE):` -> `bool T15Cond(bool _flgT15, const char* TYPE)`

**RULE 8: Function Parameter Naming**
- Parameter names should match exactly between Python and C implementations
- Use the same variable naming conventions from the original python files
- Include TYPE parameter in both Python and C
- Example: Python `T15Cond(_flgT15, TYPE)` -> C `T15Cond(bool _flgT15, const char* TYPE)`

**RULE 9: (t-@) Variable Naming Consistency**
- All (t-@) variables must follow the strict Remove the (t-@) notation.
  ```c
  example2:
  MoFRelsMngt_flgVHyst(t-@) should be renamed to MoFRelsMngt_flgVHyst. 
 
  ```

**RULE 10: Function Documentation Standards**
- Use simple C-style comments (/* */) for function documentation
- DO NOT use Doxygen-style comments (/** */)
- DO NOT include @brief, @param, @return tags
- Keep function comments minimal and focused on implementation details
- Document TYPE selector options only when necessary for clarity
- Example format:
  ```c
  /* Function: BrakeStatus */
  bool BrakeStatus(bool flgBrkMai, bool flgBrkRdnt, bool flgBrkErr, const char* TYPE)
  {
      /* Implementation logic here */
  }
  ```

**RULE 11: Unified Function Return Types**
- Unified functions with multiple output types should return `float` and use casting
- This allows a single function to return different data types (bool, uint8, etc.)
- Use explicit casting when returning: `return (float)boolValue;` or `return (float)uint8Value;`
- Output wrapper functions should call unified function and cast back to appropriate type
- Example:
  ```c
  float Hysterisis(sint16 bas_vVeh, bool flgErrVSig, const char* TYPE)
  {
      if (strcmp(TYPE, "flgVHyst") == 0) {
          return (float)flgVHyst;
      }
      if (strcmp(TYPE, "_bbLoc1") == 0) {
          return (float)bbLoc1_temp;
      }
  }
  ```

**RULE 12: Include Structure Requirements**
- Always include project-specific headers first:
  ```c
  #include "my_pavast_stubs.h"
  #include "my_stubs.h"
  ```
- Then include the generated header file
- Use relative paths with proper directory structure
- Include order: project stubs first, then generated header

**RULE 13: Variable Declaration Organization**
- Group external variable declarations by category:
  - Configuration parameters (constants ending with _C)
  - Local variables (module-specific variables)
  - External system variables (from other modules)
  - System constants (#define statements)
- Use descriptive comments for each group
- Follow the example structure for consistency

**RULE 14: Function Declaration Organization**
- Group function declarations by Python function with wrapper functions immediately following
- Use consistent comment format: `/* Function: FunctionName */`
- Include wrapper function declarations for each output
- Maintain alphabetical order within groups when possible
- Dont replace/use the variable names same as output wrapper names inside the function as it is only used in the wrapper function to return the value.

**RULE 15: Handling Duplicate Function Names**
- When multiple functions share the same name but have different input parameters, ensure unique naming by adding numerical suffixes (`_1`, `_2`, etc.)
- Keep the first occurrence of the function name unchanged
- Add suffix to subsequent occurrences starting with `_1`
- Apply the same suffix pattern to wrapper functions that call the renamed functions
- Apply the same suffix pattern to output variable declarations (e.g., `MoFRelsMngt_flgBrkSt_Out_1_t`)
- Example:
  ```c
  /* First function - unchanged */
  bool BrakeStatus(bool flgBrkMai, bool flgBrkRdnt, bool flgBrkErr, const char* TYPE)
  {
      bool flgBrkSt;
      /* Implementation */
      return flgBrkSt;
  }
  
  bool MoFRelsMngt_flgBrkSt_Out(void)
  {
      return (MoFRelsMngt_flgBrkSt_Out_t = BrakeStatus(MoFBrk_flgBrkMai, MoFBrk_flgBrkRdnt, MoFBrk_flgBrkErr, "flgBrkSt"));
  }
  
  /* Second function - renamed with suffix */
  bool BrakeStatus_1(bool flgBrkMai_1, bool flgBrkRdnt_2, bool flgBrkErr_3, const char* TYPE)
  {
      bool flgBrkSt;
      /* Implementation */
      return flgBrkSt;
  }
  
  bool MoFRelsMngt_flgBrkSt_Out_1(void)
  {
      return (MoFRelsMngt_flgBrkSt_Out_1_t = BrakeStatus_1(MoFBrk_flgBrkMai_1, MoFBrk_flgBrkRdnt_2, MoFBrk_flgBrkErr_3, "flgBrkSt"));
  }
  ```

**RULE 16: Handling Duplicate Output Wrapper Functions**
- When output wrapper functions have duplicate names with different input parameters, ensure unique naming by adding numerical suffixes
- Keep the first wrapper function unchanged
- Add suffix to subsequent wrappers starting with `_1`
- Ensure corresponding output variable declarations also use the same suffix
- Maintain consistent variable mapping across all wrapper variants
- Example:
  ```c
  /* First wrapper - unchanged */
  bool MoFRelsMngt_flgVHyst_Out(void)
  {
      return (MoFRelsMngt_flgVHyst_Out_t = (bool)Hysterisis(MoFBas_vVeh, MoFBas_flgErrVSig, "flgVHyst"));
  }
  
  /* Second wrapper - with suffix */
  bool MoFRelsMngt_flgVHyst_Out_1(void)
  {
      return (MoFRelsMngt_flgVHyst_Out_1_t = (bool)Hysterisis(MoFBas_vVeh_1, MoFBas_flgErrVSig_2, "flgVehV"));
  }
  ```
- Note: Ensure the output variable declarations match the wrapper function suffix (e.g., `MoFRelsMngt_flgVHyst_Out_t` vs `MoFRelsMngt_flgVHyst_Out_1_t`)

**RULE 17: Multi-Output Unified Function Implementation Pattern**
- When a single Python function returns multiple outputs based on a TYPE selector, implement as one C function returning `float` with complete TYPE-based branching
- Declare all output variables as local variables within the unified function with their actual types (bool, uint8, etc.)
- Implement the complete logic for all outputs within the unified function
- Use `strcmp(TYPE, "outputName")` for each TYPE selector check
- Cast each local variable to `float` when returning: `return (float)localVar;`
- Create separate wrapper functions for each output that:
  - Have void parameters `functionName_Out(void)`
  - Call the unified function with appropriate TYPE string
  - Cast the float return value back to the correct type
  - Store result in the corresponding output variable
- Declare output variables externally with `_t` suffix matching wrapper function name
- Example complete implementation:
  ```c
  /* Unified function returning float */
  float Hysterisis(sint16 bas_vVeh, bool flgErrVSig, const char* TYPE)
  {
      bool flgVHyst;
      bool flgVehV;
      uint8 bbLoc1_temp;
      
      /* Complete logic for all outputs */
      if (bas_vVeh >= MoFRelsMngt_vVehDrvThd_C) {
          flgVHyst = true;
      } else if (bas_vVeh <= MoFRelsMngt_vVehHaltThd_C) {
          flgVHyst = false;
      } else {
          flgVHyst = MoFRelsMngt_flgVHyst;
      }
      
      if ((flgVHyst == true) && (!flgErrVSig)) {
          flgVehV = true;
      } else {
          flgVehV = false;
      }
      
      bbLoc1_temp = (flgVHyst == true) ? (MoFRelsMngtPtRels_bbLoc1 | 8U) : (MoFRelsMngtPtRels_bbLoc1 & 239U);
      bbLoc1_temp = (flgVehV == true) ? (bbLoc1_temp | 1U) : (bbLoc1_temp & 253U);
      
      /* TYPE selector returns */
      if (strcmp(TYPE, "flgVHyst") == 0) {
          return (float)flgVHyst;
      }
      if (strcmp(TYPE, "flgVehV") == 0) {
          return (float)flgVehV;
      }
      if (strcmp(TYPE, "_bbLoc1") == 0) {
          return (float)bbLoc1_temp;
      }
  }
  
  /* Output wrapper functions with type-specific casting */
  bool MoFRelsMngt_flgVHyst_Out(void)
  {
      return (MoFRelsMngt_flgVHyst_Out_t = (bool)Hysterisis(MoFBas_vVeh, MoFBas_flgErrVSig, "flgVHyst"));
  }
  
  bool MoFRelsMngt_flgVehV_Out(void)
  {
      return (MoFRelsMngt_flgVehV_Out_t = (bool)Hysterisis(MoFBas_vVeh, MoFBas_flgErrVSig, "flgVehV"));
  }
  
  uint8 MoFRelsMngtPtRels_bbLoc1_Out(void)
  {
      return (MoFRelsMngtPtRels_bbLoc1_Out_t = (uint8)Hysterisis(MoFBas_vVeh, MoFBas_flgErrVSig, "_bbLoc1"));
  }
  ```
- Note: All computation logic should be in the unified function; wrapper functions only handle type casting and variable assignment

 

### 1.2 Operator Conversions

| TPT Operator | Python Equivalent | C/C++ Equivalent |
|--------------|-------------------|-----------------|
| \|\| (logical OR) | or | \|\| |
| && (logical AND) | and | && |
| ! (logical NOT) | not | ! |
| == (equality) | == | == |
| != (inequality) | != | != |
| >= (greater/equal) | >= | >= |
| <= (less/equal) | <= | <= |
| ? : (ternary) | val_if_true if condition else val_if_false | condition ? val_if_true : val_if_false |

### 1.3 Data Type Conversions

| TPT Type | Python Type | C/C++ Type |
|----------|-------------|------------|
| TPT.Boolean() | bool | bool |
| TPT.BooleanX() | bool | bool |
| TPT.Float() | float | float |
| TPT.FloatX() | float | float |
| TPT.UInt8() | int (0-255) | uint8 |
| TPT.UInt8X() | int (0-255) | uint8 |
| TPT.UInt16() | int (0-65535) | uint16 |
| TPT.UInt32() | int | uint32 |
| TPT.Int8() | int (-128 to 127) | int |
| TPT.Int16() | int | int |
| TPT.String() | str | char* |

### 1.4 Migration Rules

**CRITICAL MIGRATION RULES:**

1. **Direct Python-to-C Function Mapping**
   - Every Python function must have a corresponding C function with identical logic
   - Function parameters must match exactly (same names, equivalent types)
   - No intermediate structures or pointer-based interfaces allowed

2. **Eliminate Pointer-Based Input/Output**
   - Remove all `const Type_Input_t*` and `Type_Output_t*` parameters
   - Replace with direct parameter passing: `bool Function(param1, param2, param3)`
   - Return values directly instead of writing to output structures

3. **Example of WRONG vs RIGHT approach:**
   ```c
   // WRONG - Pointer-based (old style)
   bool ChargerPlugCond_Calculate(const ChargerPlugCond_Input_t* inputs, 
                                  ChargerPlugCond_Output_t* outputs);
   
   // RIGHT - Direct conversion (new style)
   bool ChargerPlugCond(int stChrgPlgIns, bool flgChrgPlgInsCanErr);
   ```
**Migration Process:**
1. Analyze existing Python implementation
2. Create C function with identical parameter list
3. Implement identical logic in C