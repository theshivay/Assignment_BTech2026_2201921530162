# Encapsulation in Real-World Industries

## Definition
Encapsulation is a fundamental principle of object-oriented programming that binds data and methods operating on that data into a single unit while restricting direct access to some of the object's details.

## Real-World Example: Banking System
In banking systems, customer details like account balance should be private and only accessible via authorized methods. This prevents unauthorized modifications.

### C++ Implementation
```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;

public:
    BankAccount(string holder, double initialBalance) {
        accountHolder = holder;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " | New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds or invalid amount." << endl;
        }
    }

    void displayBalance() {
        cout << "Account Holder: " << accountHolder << " | Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account("John Doe", 1000.0);
    account.displayBalance();
    account.deposit(500);
    account.withdraw(300);
    account.withdraw(1500);
    return 0;
}
```

## Explanation
- The `balance` variable is private to prevent direct modification.
- Public methods `deposit()`, `withdraw()`, and `displayBalance()` allow controlled access to the balance.
- This ensures data security and prevents unauthorized access, reflecting encapsulation in banking systems.

## Benefits
- **Data Security**: Prevents direct access to sensitive information.
- **Code Maintainability**: Encapsulated code is easier to modify and maintain.
- **Modularity**: Separation of concerns makes debugging simpler.

