# 1. C++ Method Overriding - Super Keyword Equivalent

## Problem Statement
In C++, method overriding allows a subclass to provide a specific implementation of a function already defined in its superclass. We can use the `::` scope resolution operator to access the overridden method in the base class.

### Objective
Modify the given C++ code to ensure that the output matches the expected result.

## Expected Output
```
Hello I am a motorcycle, I am a cycle with an engine.
My ancestor is a cycle who is a vehicle with pedals.
```

## Given Code
```cpp
#include <iostream>
using namespace std;

class BiCycle {
public:
    string define_me() {
        return "a vehicle with pedals.";
    }
};

class MotorCycle : public BiCycle {
public:
    string define_me() {
        return "a cycle with an engine.";
    }
    
    MotorCycle() {
        cout << "Hello I am a motorcycle, I am " << define_me() << endl;
        
        string temp = BiCycle::define_me(); // Using scope resolution to call base class method
        cout << "My ancestor is a cycle who is " << temp << endl;
    }
};

int main() {
    MotorCycle M;
    return 0;
}
```

## Explanation
1. The `MotorCycle` class overrides the `define_me()` method of the `BiCycle` class.
2. Inside the `MotorCycle` constructor, `define_me()` is called to print the subclass definition.
3. The `BiCycle::define_me()` method is used to invoke the overridden method from `BiCycle`, ensuring the correct ancestor description is printed.

## Key Concepts
- **Method Overriding**: A subclass redefines a method of its base class.
- **Scope Resolution Operator (`::`)**: Used to call the superclass method from the subclass.

## How to Run
1. Copy the provided C++ code into a file (e.g., `main.cpp`).
2. Compile the program using:
   ```sh
   g++ main.cpp -o output
   ```
3. Run the program using:
   ```sh
   ./output
   ```

---

