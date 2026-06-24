# Matrix Operations Program

## Description
A comprehensive matrix operations program using **functions** and **2D arrays** in C. It supports the following operations:
- Matrix Addition
- Matrix Multiplication
- Matrix Transpose

## Features
- Functions for each matrix operation
- 2D arrays for matrix storage
- Input validation
- Dynamic matrix size support (up to 10x10)
- Clear display of input and result matrices

## How to Compile and Run

### Using GCC:
```bash
gcc matrix_operations.c -o matrix_operations
matrix_operations.exe
```

### Using MinGW (Windows):
```bash
mingw32-gcc matrix_operations.c -o matrix_operations
matrix_operations.exe
```

## Program Flow
1. Display main menu with operations
2. Select operation (Add, Multiply, Transpose, or Exit)
3. Input matrix dimensions and elements
4. Perform calculation using respective function
5. Display input matrices and result
6. Continue until user selects Exit

## Functions Used

### Core Functions
- `void readMatrix(...)` - Read matrix elements from user
- `void displayMatrix(...)` - Display matrix in formatted output
- `void addMatrices(...)` - Add two matrices of same dimension
- `void multiplyMatrices(...)` - Multiply two compatible matrices
- `void transposeMatrix(...)` - Find transpose of a matrix

### Constraints
- Matrix dimensions: Max 10x10
- For multiplication: columns of matrix1 must equal rows of matrix2

## Example Usage

### Matrix Addition
```
--- MATRIX ADDITION ---
Enter number of rows and columns: 2 2

Enter first matrix:
Element [0][0]: 1
Element [0][1]: 2
Element [1][0]: 3
Element [1][1]: 4

Result (Matrix 1 + Matrix 2):
Matrix (2 x 2):
5	6
7	8
```

### Matrix Transpose
```
--- MATRIX TRANSPOSE ---
Original Matrix:
1	2	3
4	5	6

Transposed Matrix:
1	4
2	5
3	6
```

## Maximum Limits
- MAX_ROWS: 10
- MAX_COLS: 10
