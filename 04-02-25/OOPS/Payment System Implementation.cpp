#include <iostream>
using namespace std;

// Abstract class implementing abstraction
class Payment {
public:
    virtual void processPayment(double amount) = 0; // Pure virtual function
};

// Derived class implementing Credit Card payment
class CreditCardPayment : public Payment {
public:
    void processPayment(double amount) override {
        cout << "Processing Credit Card Payment of $" << amount << endl;
    }
};

// Derived class implementing PayPal payment
class PayPalPayment : public Payment {
public:
    void processPayment(double amount) override {
        cout << "Processing PayPal Payment of $" << amount << endl;
    }
};

// Main function
int main() {
    Payment* payment;
    CreditCardPayment creditCard;
    PayPalPayment payPal;
    
    // Using abstraction to process payments
    payment = &creditCard;
    payment->processPayment(100.50);
    
    payment = &payPal;
    payment->processPayment(75.25);
    
    return 0;
}