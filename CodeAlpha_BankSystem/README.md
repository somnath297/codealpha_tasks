# Banking System Management

## Description
A comprehensive banking system using **structures**, **functions**, and **file handling** in C. It manages customer accounts with the following features:
- Create new accounts
- Deposit money
- Withdraw money
- Check balance
- View all accounts
- Persistent storage using file handling

## Features
- Account structure with account number, holder name, and balance
- File handling for persistent data storage
- Multiple account management (up to 100 accounts)
- Error handling for various scenarios
- User-friendly menu interface
- Automatic data save after each transaction

## How to Compile and Run

### Using GCC:
```bash
gcc banking_system.c -o banking_system
banking_system.exe
```

### Using MinGW (Windows):
```bash
mingw32-gcc banking_system.c -o banking_system
banking_system.exe
```

## File Structure

### Data Storage
- **Filename:** `bank_data.dat` (binary file)
- **Location:** Same directory as the executable
- **Contents:** Account structures persisted across program runs

### Account Structure
```c
typedef struct {
    int accountNumber;
    char accountHolder[50];
    float balance;
} Account;
```

## Program Functions

### Account Management
- `void createAccount()` - Create a new bank account
- `void deposit()` - Deposit money to an account
- `void withdraw()` - Withdraw money from an account
- `void checkBalance()` - Display account balance and details
- `void displayAllAccounts()` - Show all existing accounts

### File Operations
- `void saveToFile()` - Save all accounts to binary file
- `void loadFromFile()` - Load accounts from binary file

### Helper Functions
- `int findAccount(int accountNumber)` - Search for account by number

## Menu Options
```
--- MAIN MENU ---
1. Create new account
2. Deposit money
3. Withdraw money
4. Check balance
5. Display all accounts
6. Exit
```

## Example Usage

### Creating Account
```
--- CREATE NEW ACCOUNT ---
Enter account number: 1001
Enter account holder name: John Doe
Enter initial balance: 5000
Account created successfully!
```

### Deposit Money
```
--- DEPOSIT ---
Enter account number: 1001
Enter amount to deposit: 2000
Deposit successful!
New balance: Rs. 7000.00
```

### Withdraw Money
```
--- WITHDRAW ---
Enter account number: 1001
Enter amount to withdraw: 1000
Withdrawal successful!
New balance: Rs. 6000.00
```

### Check Balance
```
--- CHECK BALANCE ---
Enter account number: 1001

--- ACCOUNT DETAILS ---
Account Number: 1001
Account Holder: John Doe
Balance: Rs. 6000.00
```

## Error Handling
- Account not found error
- Insufficient balance error
- Maximum accounts reached error
- Negative balance prevention
- File operation errors

## Maximum Limits
- MAX_ACCOUNTS: 100
- Account Holder Name: 50 characters
- All data is persisted in `bank_data.dat`

## Data Persistence
The program automatically saves data after each transaction:
- New account creation
- Deposit operation
- Withdrawal operation

Data is automatically loaded when the program starts if `bank_data.dat` exists.
