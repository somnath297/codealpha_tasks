#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define FILENAME "bank_data.dat"

// Structure to store account information
typedef struct {
    int accountNumber;
    char accountHolder[50];
    float balance;
} Account;

// Global array to store accounts
Account accounts[MAX_ACCOUNTS];
int totalAccounts = 0;

// Function to save all accounts to file
void saveToFile() {
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL) {
        printf("Error: Unable to open file for writing!\n");
        return;
    }

    fwrite(&totalAccounts, sizeof(int), 1, file);
    fwrite(accounts, sizeof(Account), totalAccounts, file);

    fclose(file);
    printf("Data saved successfully!\n");
}

// Function to load accounts from file
void loadFromFile() {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        // File doesn't exist yet
        totalAccounts = 0;
        return;
    }

    fread(&totalAccounts, sizeof(int), 1, file);
    fread(accounts, sizeof(Account), totalAccounts, file);

    fclose(file);
}

// Function to create a new account
void createAccount() {
    if (totalAccounts >= MAX_ACCOUNTS) {
        printf("Error: Maximum accounts reached!\n");
        return;
    }

    Account newAccount;

    printf("\n--- CREATE NEW ACCOUNT ---\n");
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);

    // Check if account already exists
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == newAccount.accountNumber) {
            printf("Error: Account already exists!\n");
            return;
        }
    }

    printf("Enter account holder name: ");
    scanf("%s", newAccount.accountHolder);

    printf("Enter initial balance: ");
    scanf("%f", &newAccount.balance);

    if (newAccount.balance < 0) {
        printf("Error: Balance cannot be negative!\n");
        return;
    }

    accounts[totalAccounts] = newAccount;
    totalAccounts++;

    saveToFile();
    printf("Account created successfully!\n");
}

// Function to find account by account number
int findAccount(int accountNumber) {
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return i;
        }
    }
    return -1;
}

// Function to deposit money
void deposit() {
    int accountNumber;
    float amount;

    printf("\n--- DEPOSIT ---\n");
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    int index = findAccount(accountNumber);
    if (index == -1) {
        printf("Error: Account not found!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Error: Deposit amount must be positive!\n");
        return;
    }

    accounts[index].balance += amount;
    saveToFile();

    printf("Deposit successful!\n");
    printf("New balance: Rs. %.2f\n", accounts[index].balance);
}

// Function to withdraw money
void withdraw() {
    int accountNumber;
    float amount;

    printf("\n--- WITHDRAW ---\n");
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    int index = findAccount(accountNumber);
    if (index == -1) {
        printf("Error: Account not found!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Error: Withdrawal amount must be positive!\n");
        return;
    }

    if (amount > accounts[index].balance) {
        printf("Error: Insufficient balance!\n");
        printf("Available balance: Rs. %.2f\n", accounts[index].balance);
        return;
    }

    accounts[index].balance -= amount;
    saveToFile();

    printf("Withdrawal successful!\n");
    printf("New balance: Rs. %.2f\n", accounts[index].balance);
}

// Function to check account balance
void checkBalance() {
    int accountNumber;

    printf("\n--- CHECK BALANCE ---\n");
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    int index = findAccount(accountNumber);
    if (index == -1) {
        printf("Error: Account not found!\n");
        return;
    }

    printf("\n--- ACCOUNT DETAILS ---\n");
    printf("Account Number: %d\n", accounts[index].accountNumber);
    printf("Account Holder: %s\n", accounts[index].accountHolder);
    printf("Balance: Rs. %.2f\n", accounts[index].balance);
}

// Function to display all accounts
void displayAllAccounts() {
    if (totalAccounts == 0) {
        printf("\nNo accounts found!\n");
        return;
    }

    printf("\n--- ALL ACCOUNTS ---\n");
    printf("Account No.\t\tHolder Name\t\tBalance\n");
    printf("=========================================================\n");

    for (int i = 0; i < totalAccounts; i++) {
        printf("%d\t\t\t%s\t\t\tRs. %.2f\n",
               accounts[i].accountNumber,
               accounts[i].accountHolder,
               accounts[i].balance);
    }
}

int main() {
    int choice;

    // Load data from file when program starts
    loadFromFile();

    printf("================================================\n");
    printf("       BANKING SYSTEM MANAGEMENT               \n");
    printf("================================================\n\n");

    while (1) {
        printf("\n--- MAIN MENU ---\n");
        printf("1. Create new account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Check balance\n");
        printf("5. Display all accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;

            case 2:
                deposit();
                break;

            case 3:
                withdraw();
                break;

            case 4:
                checkBalance();
                break;

            case 5:
                displayAllAccounts();
                break;

            case 6:
                printf("\nThank you for using Banking System!\n");
                printf("================================================\n");
                exit(0);

            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    }

    return 0;
}
