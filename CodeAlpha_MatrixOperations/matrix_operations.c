#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Function to read a matrix
void readMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    printf("\nMatrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to add two matrices
void addMatrices(int matrix1[MAX_ROWS][MAX_COLS], 
                 int matrix2[MAX_ROWS][MAX_COLS],
                 int result[MAX_ROWS][MAX_COLS], 
                 int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int matrix1[MAX_ROWS][MAX_COLS], 
                      int matrix2[MAX_ROWS][MAX_COLS],
                      int result[MAX_ROWS][MAX_COLS], 
                      int rows1, int cols1, int cols2) {
    // Initialize result matrix with 0
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
        }
    }

    // Perform multiplication
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to find transpose of a matrix
void transposeMatrix(int matrix[MAX_ROWS][MAX_COLS],
                     int transpose[MAX_ROWS][MAX_COLS],
                     int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int matrix1[MAX_ROWS][MAX_COLS];
    int matrix2[MAX_ROWS][MAX_COLS];
    int result[MAX_ROWS][MAX_COLS];
    int transpose[MAX_ROWS][MAX_COLS];
    int choice, rows, cols, rows1, cols1, rows2, cols2;

    printf("================================================\n");
    printf("          MATRIX OPERATIONS PROGRAM             \n");
    printf("================================================\n\n");

    while (1) {
        printf("\nSelect an operation:\n");
        printf("1. Add two matrices\n");
        printf("2. Multiply two matrices\n");
        printf("3. Find transpose of a matrix\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n--- MATRIX ADDITION ---\n");
                printf("Enter number of rows and columns: ");
                scanf("%d %d", &rows, &cols);

                if (rows > MAX_ROWS || cols > MAX_COLS) {
                    printf("Matrix size exceeds maximum limit (%d x %d)\n", MAX_ROWS, MAX_COLS);
                    break;
                }

                printf("\nEnter first matrix:\n");
                readMatrix(matrix1, rows, cols);

                printf("\nEnter second matrix:\n");
                readMatrix(matrix2, rows, cols);

                addMatrices(matrix1, matrix2, result, rows, cols);

                printf("\nMatrix 1:");
                displayMatrix(matrix1, rows, cols);

                printf("Matrix 2:");
                displayMatrix(matrix2, rows, cols);

                printf("Result (Matrix 1 + Matrix 2):");
                displayMatrix(result, rows, cols);
                break;

            case 2:
                printf("\n--- MATRIX MULTIPLICATION ---\n");
                printf("Enter rows and columns for matrix 1: ");
                scanf("%d %d", &rows1, &cols1);
                printf("Enter rows and columns for matrix 2: ");
                scanf("%d %d", &rows2, &cols2);

                if (cols1 != rows2) {
                    printf("Error: Number of columns in matrix 1 must equal number of rows in matrix 2!\n");
                    break;
                }

                if (rows1 > MAX_ROWS || cols2 > MAX_COLS) {
                    printf("Result matrix size exceeds maximum limit\n");
                    break;
                }

                printf("\nEnter first matrix (%d x %d):\n", rows1, cols1);
                readMatrix(matrix1, rows1, cols1);

                printf("\nEnter second matrix (%d x %d):\n", rows2, cols2);
                readMatrix(matrix2, rows2, cols2);

                multiplyMatrices(matrix1, matrix2, result, rows1, cols1, cols2);

                printf("\nMatrix 1:");
                displayMatrix(matrix1, rows1, cols1);

                printf("Matrix 2:");
                displayMatrix(matrix2, rows2, cols2);

                printf("Result (Matrix 1 * Matrix 2):");
                displayMatrix(result, rows1, cols2);
                break;

            case 3:
                printf("\n--- MATRIX TRANSPOSE ---\n");
                printf("Enter number of rows and columns: ");
                scanf("%d %d", &rows, &cols);

                if (rows > MAX_ROWS || cols > MAX_COLS) {
                    printf("Matrix size exceeds maximum limit\n");
                    break;
                }

                printf("\nEnter the matrix (%d x %d):\n", rows, cols);
                readMatrix(matrix1, rows, cols);

                transposeMatrix(matrix1, transpose, rows, cols);

                printf("\nOriginal Matrix:");
                displayMatrix(matrix1, rows, cols);

                printf("Transposed Matrix:");
                displayMatrix(transpose, cols, rows);
                break;

            case 4:
                printf("\nThank you for using Matrix Operations Program!\n");
                printf("================================================\n");
                exit(0);

            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}
