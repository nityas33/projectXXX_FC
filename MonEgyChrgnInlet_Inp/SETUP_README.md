# MonEgyChrgnInlet_Inp - BCU Migration Framework

This module was created using the BCU Migration Framework Setup.

## Configuration
- Setup Type: full
- Language: both
- Created: 2026-10-13 12:25:31
- Project Path: C:\Users\VJB3KOR\Desktop\TASK\New folder (2)\MonEgyChrgnInlet_Inp

## Directory Structure
- `Script/` - Python implementations
- `CAsseslets/` - C implementations
- `testsuite/` - Unit tests
- `tauto/` - TPT specifications and definitions
- `examples/` - Working examples
- `tools/` - Development tools and documentation
- `docs/` - Project documentation
- `Migration/` - Migration framework tools

## Getting Started
1. Review `Migration/docs/README.md`
2. Update `Script/common_imports.py` with your signals
3. Use CoreFunction templates for new functions
4. Run tests to validate implementations

## BCU Migration Commands
```batch
# Extract TPT scripts to Python
cd Migration\tools
python bcu_migration_framework.py --extract

# Migrate test cases
python bcu_migration_framework.py --migrate input.c output.c

# Build C implementations
cd ..\..\CAsseslets
make

# Run Python tests
cd ..\testsuite
python test_your_function.py
```

## Documentation
- `Migration/docs/migration_mapping.md` - Track your progress
- `Migration/docs/migration_next_steps.md` - Planning document
- `Migration/docs/README.md` - Project overview
- `Migration/Template/Conversion_Rules.md` - Conversion rules
- `Migration/Template/Conversion_Template.md` - Sample conversions
