# Multilevel Inheritance Introduction - Hackerrank

## Problem Statement
This challenge is an extension of the previous challenge, **Inheritance-Introduction**. It introduces the concept of multi-level inheritance.

In multi-level inheritance:
- Class A is the base class.
- Class B is derived from Class A.
- Class C is derived from Class B.

An object of Class C can access the functions of both Class A and Class B. This mechanism is called **multi-level inheritance**.

### Objective
Create a class called `Equilateral` which inherits from `Isosceles`. The `Equilateral` class should have a function such that the output matches the expected result.

### Expected Output
```
I am an equilateral triangle
I am an isosceles triangle
I am a triangle
```

---

## Approach
1. Define a base class `Triangle` with a member function `triangle()`.
2. Define a derived class `Isosceles` that inherits from `Triangle` and implements the function `isosceles()`.
3. Define a derived class `Equilateral` that inherits from `Isosceles` and implements the function `equilateral()`.
4. Create an object of the `Equilateral` class in the `main()` function and call the respective functions to generate the required output.

---

## Code Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

class Triangle {
    public:
        void triangle() {
            cout << "I am a triangle\n";
        }
};

class Isosceles : public Triangle {
    public:
        void isosceles() {
            cout << "I am an isosceles triangle\n";
        }
};

// Write your code here
class Equilateral : public Isosceles {
    public:
        void equilateral() {
            cout << "I am an equilateral triangle\n";
        }
};

int main() {
    Equilateral eqr;
    eqr.equilateral();
    eqr.isosceles();
    eqr.triangle();
    return 0;
}
```

---

## Explanation
1. `Triangle` is the base class with a method `triangle()`.
2. `Isosceles` is derived from `Triangle` and has an additional method `isosceles()`.
3. `Equilateral` is derived from `Isosceles` and introduces the method `equilateral()`.
4. The `main()` function creates an object of `Equilateral`, demonstrating access to methods from all three classes.

---


