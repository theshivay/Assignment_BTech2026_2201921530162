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