# Inheritance Introduction - Hackerrank

## Problem Statement
Implement inheritance in C++ by creating a base class `Triangle` and a derived class `Isosceles`. The base class should have a method to print "I am a triangle," and the derived class should have methods to:
1. Print "I am an isosceles triangle."
2. Print "In an isosceles triangle two sides are equal."

The derived class should also inherit the functionality of the base class.

### Example
**Output:**
```
I am an isosceles triangle
In an isosceles triangle two sides are equal
I am a triangle
```

---

## Platform
Solved on **Hackerrank**: [Inheritance Introduction](https://www.hackerrank.com/challenges/inheritance-introduction/problem)

---

## Approach

### Explanation
1. Create a base class `Triangle` with a public method `triangle()` to print "I am a triangle."
2. Create a derived class `Isosceles` that inherits from `Triangle`.
3. Add a method `isosceles()` in the `Isosceles` class to print specific messages about isosceles triangles.
4. Use an instance of the `Isosceles` class to call both `isosceles()` and `triangle()` methods, demonstrating inheritance.

**Code:**
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
        cout << "In an isosceles triangle two sides are equal\n";
    }
};

int main() {
    Isosceles isc;
    isc.isosceles();
    isc.triangle();
    return 0;
}
```

**Output:**
```
I am an isosceles triangle
In an isosceles triangle two sides are equal
I am a triangle
```

**Time Complexity:** O(1) (Constant number of operations)  
**Space Complexity:** O(1) (No extra space used)

---

