# 1. C++ Abstraction - Payment System Implementation

## Problem Statement

This project demonstrates the implementation of **Abstraction** in C++ by defining an abstract class `Payment` and concrete subclasses `CreditCardPayment` and `PayPalPayment`.

## Problem Description

The goal is to:

1. Create an **abstract class `Payment`** with:
   - A **pure virtual function** `processPayment(double amount)` to enforce implementation in derived classes.
2. Create **two derived classes**:
   - `CreditCardPayment`: Implements `processPayment` for credit card transactions.
   - `PayPalPayment`: Implements `processPayment` for PayPal transactions.

Abstraction allows us to define a general interface (`Payment`) while hiding implementation details in concrete classes.

---

## Solution Overview

### Classes and Methods

1. **`Payment` (Abstract Class)**:
   - Defines a pure virtual function `processPayment(double amount)`.
   - Enforces that all payment types must implement their own version of `processPayment`.

2. **`CreditCardPayment` (Derived Class)**:
   - Implements `processPayment`, simulating a credit card transaction.

3. **`PayPalPayment` (Derived Class)**:
   - Implements `processPayment`, simulating a PayPal transaction.

4. **`main` Function**:
   - Demonstrates abstraction by calling `processPayment` on different payment types using a `Payment*` pointer.

---

## Code

```cpp
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
```

---

## Sample Output

When the program runs, it outputs:

```
Processing Credit Card Payment of $100.5
Processing PayPal Payment of $75.25
```

### Explanation:
1. **Abstraction via Pure Virtual Function**: The `Payment` class defines `processPayment`, but does not implement it.
2. **Method Implementation in Derived Classes**: `CreditCardPayment` and `PayPalPayment` provide their own implementations of `processPayment`.
3. **Usage of Base Class Pointer**: A `Payment*` pointer is used to call derived class methods dynamically.

---

## Key Concepts

1. **Abstraction**:
   - Hides implementation details while exposing only necessary functionalities.
   - The `Payment` class acts as an interface for payment processing.

2. **Pure Virtual Functions**:
   - `processPayment` is a pure virtual function, making `Payment` an abstract class.
   - Forces derived classes to provide implementations.

3. **Dynamic Polymorphism**:
   - A base class pointer (`Payment*`) is used to call the appropriate derived class method at runtime.

---

## How to Run

1. Copy the code into a file named `payment_system.cpp`.
2. Compile the file:
   ```bash
   g++ payment_system.cpp -o payment_system
   ```
3. Run the compiled file:
   ```bash
   ./payment_system
   ```

This implementation adheres to the principles of **Abstraction**, ensuring a clean and maintainable design in real-world applications like payment processing systems.

