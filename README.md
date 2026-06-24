# CodeAlpha Tasks - C Programming Projects

A collection of three comprehensive C programming projects showcasing different concepts and techniques.

---

## Project Overview

### 1. **Calculator Program** (`CodeAlpha_CalculatorProgram`)
**Key Concepts:** Do-While Loop, Switch Case, Functions

A basic calculator with menu-driven interface that performs:
- Addition
- Subtraction  
- Multiplication
- Division

**Files:**
- `calculator.c` - Main program
- `compile_and_run.bat` - Batch file to compile and run
- `README.md` - Detailed documentation

**How to Run:**
```bash
cd CodeAlpha_CalculatorProgram
compile_and_run.bat
```

---

### 2. **Matrix Operations** (`CodeAlpha_MatrixOperations`)
**Key Concepts:** Functions, 2D Arrays, Nested Loops

Performs advanced matrix operations:
- Matrix Addition
- Matrix Multiplication
- Matrix Transpose

**Files:**
- `matrix_operations.c` - Main program
- `compile_and_run.bat` - Batch file to compile and run
- `README.md` - Detailed documentation

**Features:**
- Support for matrices up to 10x10
- Input validation
- Clear formatted output
- Function-based modular design

**How to Run:**
```bash
cd CodeAlpha_MatrixOperations
compile_and_run.bat
```

---

### 3. **Banking System** (`CodeAlpha_BankSystem`)
**Key Concepts:** Structures, File Handling, Functions, Data Persistence

A complete banking system with:
- Create new accounts
- Deposit money
- Withdraw money
- Check balance
- View all accounts
- Persistent data storage

**Files:**
- `banking_system.c` - Main program
- `compile_and_run.bat` - Batch file to compile and run
- `README.md` - Detailed documentation
- `bank_data.dat` - Binary data file (created after first run)

**Features:**
- Account structure-based design
- Binary file storage for data persistence
- Support for up to 100 accounts
- Comprehensive error handling
- Automatic data save after each transaction

**How to Run:**
```bash
cd CodeAlpha_BankSystem
compile_and_run.bat
```

---

## Requirements

- GCC compiler (MinGW on Windows)
- Command Prompt or PowerShell
- No external libraries required (uses only standard C libraries)

---

## Compilation Instructions

### Option 1: Using Batch Files (Easiest)
Navigate to each project folder and double-click `compile_and_run.bat`

### Option 2: Manual Compilation
```bash
# Calculator
gcc calculator.c -o calculator
calculator.exe

# Matrix Operations
gcc matrix_operations.c -o matrix_operations
matrix_operations.exe

# Banking System
gcc banking_system.c -o banking_system
banking_system.exe
```

---

## Program Features Summary

| Feature | Calculator | Matrix Ops | Banking |
|---------|-----------|-----------|---------|
| Do-While Loop | ✓ | - | - |
| Switch Case | ✓ | ✓ | ✓ |
| Functions | ✓ | ✓ | ✓ |
| 2D Arrays | - | ✓ | - |
| Structures | - | - | ✓ |
| File Handling | - | - | ✓ |
| Error Handling | ✓ | ✓ | ✓ |
| Input Validation | ✓ | ✓ | ✓ |

---

## Quick Start Guide

1. **Calculator:**
   - Choose operation (1-4)
   - Enter two numbers
   - View result
   - Choose 5 to exit

2. **Matrix Operations:**
   - Select operation (1-3)
   - Enter matrix dimensions
   - Input matrix elements
   - View result

3. **Banking System:**
   - Create accounts
   - Perform transactions (Deposit/Withdraw)
   - Check balances
   - Data persists between sessions

---

## Notes

- All programs use standard C libraries only
- No external dependencies required
- Data in banking system is automatically saved to `bank_data.dat`
- All programs include comprehensive error handling
- Modular function-based design for maintainability

---

## Author
CodeAlpha Programming Challenge

---

## License
Educational Use
