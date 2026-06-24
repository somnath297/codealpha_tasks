#include <stdio.h>
#include <stdlib.h>

// Function to perform addition
float add(float a, float b) {
    return a + b;
}

// Function to perform subtraction
float subtract(float a, float b) {
    return a - b;
}

// Function to perform multiplication
float multiply(float a, float b) {
    return a * b;
}

// Function to perform division
float divide(float a, float b) {
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return a / b;
}

int main() {
    float num1, num2, result;
    char operation;
    int choice;

    printf("========================================\n");
    printf("       BASIC CALCULATOR PROGRAM          \n");
    printf("========================================\n\n");

    // Do-While loop for continuous operation
    do {
        printf("\nSelect an operation:\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        // Switch case for operation selection
        switch (choice) {
            case 1:
                printf("\nEnter first number: ");
                scanf("%f", &num1);
                printf("Enter second number: ");
                scanf("%f", &num2);
                result = add(num1, num2);
                printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
                break;

            case 2:
                printf("\nEnter first number: ");
                scanf("%f", &num1);
                printf("Enter second number: ");
                scanf("%f", &num2);
                result = subtract(num1, num2);
                printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
                break;

            case 3:
                printf("\nEnter first number: ");
                scanf("%f", &num1);
                printf("Enter second number: ");
                scanf("%f", &num2);
                result = multiply(num1, num2);
                printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
                break;

            case 4:
                printf("\nEnter first number: ");
                scanf("%f", &num1);
                printf("Enter second number: ");
                scanf("%f", &num2);
                result = divide(num1, num2);
                if (num2 != 0) {
                    printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
                }
                break;

            case 5:
                printf("\nThank you for using the calculator!\n");
                printf("========================================\n");
                exit(0);

            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }

    } while (choice != 5);  // Continue until user chooses to exit

    return 0;
}
