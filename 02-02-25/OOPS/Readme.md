# 1. C++ Encapsulation - Arithmetic and Adder Classes Implementation

## Problem Statement
This project demonstrates the implementation of **Encapsulation** in C++ by defining two classes: `Arithmetic` and `Adder`.

## Problem Description

The goal is to:
1. Create a class `Arithmetic` with:
   - A private data member to store the sum.
   - A public method `add(int n1, int n2)` that takes two integers as parameters, calculates their sum, and stores it in the private data member.
   - A public method `getSum()` to return the stored sum.
2. Create a class `Adder` that:
   - Inherits from the `Arithmetic` class.
   - Uses encapsulated methods to access the sum.

Encapsulation ensures that the sum is not directly accessible from outside the class, and can only be modified through controlled methods.

---

## Solution Overview

### Classes and Methods

1. **`Arithmetic` Class**:
   - Contains a private data member `sum`.
   - Has a method `add(int n1, int n2)` to calculate and store the sum.
   - Provides a getter method `getSum()` to retrieve the sum.

2. **`Adder` Class**:
   - Inherits from the `Arithmetic` class.
   - Reuses the `add` method while keeping data encapsulated.

3. **`main` Function**:
   - Creates an instance of `Adder`.
   - Calls the `add` method and prints the results using `getSum()`.

---

## Code

```cpp
#include <iostream>
using namespace std;

// Base class implementing encapsulation
class Arithmetic {
private:
    int sum;

public:
    // Method to add two integers and store the result
    void add(int n1, int n2) {
        sum = n1 + n2;
    }
    
    // Getter method to retrieve the sum
    int getSum() {
        return sum;
    }
};

// Subclass
class Adder : public Arithmetic {
    // No additional methods or properties required
};

// Main function
int main() {
    // Create an Adder object
    Adder adder;
    
    // Perform addition operations
    adder.add(10, 32);
    cout << "Sum: " << adder.getSum() << endl;
    
    adder.add(10, 3);
    cout << "Sum: " << adder.getSum() << endl;
    
    adder.add(10, 10);
    cout << "Sum: " << adder.getSum() << endl;
    
    return 0;
}
```

---

## Sample Output

When the program runs, it outputs:

```
Sum: 42
Sum: 13
Sum: 20
```

### Explanation:
1. The private member `sum` is updated only through the `add` method, enforcing encapsulation.
2. `getSum()` ensures that the value can be accessed but not modified directly.
3. The output displays the results of calling the `add` method multiple times.

---

## Key Concepts

1. **Encapsulation**:
   - The `sum` variable is private and can only be modified using controlled methods (`add` and `getSum`).
   - Prevents direct access to the internal state from outside the class.

2. **Getter and Setter Methods**:
   - `add()` acts as a setter, modifying `sum` securely.
   - `getSum()` is a getter that provides read-only access to `sum`.

3. **Data Hiding**:
   - The implementation details of sum calculation are hidden, promoting better software design.

---

## How to Run

1. Copy the code into a file named `solution.cpp`.
2. Compile the file:
   ```bash
   g++ solution.cpp -o solution
   ```
3. Run the compiled file:
   ```bash
   ./solution
   ```

This implementation adheres to the principles of **Encapsulation**, ensuring data security and controlled access.
