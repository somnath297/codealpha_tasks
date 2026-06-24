# Calculator Program

## Description
A basic calculator program using **do-while loop** and **switch case** statements in C. It supports the following operations:
- Addition
- Subtraction
- Multiplication
- Division

## Features
- Do-while loop for continuous operation
- Switch case for operation selection
- Functions for each arithmetic operation
- Input validation for division by zero
- User-friendly menu interface

## How to Compile and Run

### Using GCC:
```bash
gcc calculator.c -o calculator
calculator.exe
```

### Using MinGW (Windows):
```bash
mingw32-gcc calculator.c -o calculator
calculator.exe
```

## Program Flow
1. Display menu with 5 options
2. Get user choice
3. Use switch case to select operation
4. Perform calculation using respective function
5. Display result
6. Continue loop until user selects Exit (option 5)

## Example Usage
```
========================================
       BASIC CALCULATOR PROGRAM          
========================================

Select an operation:
1. Addition (+)
2. Subtraction (-)
3. Multiplication (*)
4. Division (/)
5. Exit
Enter your choice (1-5): 1

Enter first number: 10
Enter second number: 5
Result: 10.00 + 5.00 = 15.00
```

## Functions Used
- `float add(float a, float b)` - Addition
- `float subtract(float a, float b)` - Subtraction
- `float multiply(float a, float b)` - Multiplication
- `float divide(float a, float b)` - Division with error handling
