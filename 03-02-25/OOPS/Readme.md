# 1. C++ Interfaces - Shape Implementation

## Problem Statement

This project demonstrates the implementation of **Interfaces** in C++ by defining a base interface `Shape` and implementing it in `Circle` and `Rectangle` classes.

## Problem Description

The goal is to:

1. Create an interface `Shape` with:
   - A pure virtual method `getArea()` to calculate the area of a shape.
   - A pure virtual method `getPerimeter()` to calculate the perimeter of a shape.
2. Implement the `Shape` interface in:
   - A `Circle` class that calculates area and perimeter based on the radius.
   - A `Rectangle` class that calculates area and perimeter based on length and width.

Interfaces allow multiple classes to follow a common structure while implementing their own versions of the required methods.

---

## Solution Overview

### Classes and Methods

1. **`Shape` Interface**:
   - Declares two pure virtual functions: `getArea()` and `getPerimeter()`.
   - Acts as a blueprint for different shapes.

2. **`Circle` Class**:
   - Implements `Shape`.
   - Defines `getArea()` and `getPerimeter()` using the formulae for a circle.

3. **`Rectangle` Class**:
   - Implements `Shape`.
   - Defines `getArea()` and `getPerimeter()` using the formulae for a rectangle.

4. **`main` Function**:
   - Demonstrates interface usage by creating objects of `Circle` and `Rectangle`.
   - Calls their respective methods and prints the results.

---

## Code

```cpp
#include <iostream>
using namespace std;

// Define the Shape interface
class Shape {
public:
    virtual double getArea() const = 0; // Pure virtual function for area
    virtual double getPerimeter() const = 0; // Pure virtual function for perimeter
};

// Implement the Interface for a Circle
class Circle: public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() const override {
        return 3.14159265359 * radius * radius;
    }
    double getPerimeter() const override {
        return 2 * 3.14159265359 * radius;
    }
};

// Implement the Interface for a Rectangle
class Rectangle: public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double getArea() const override {
        return length * width;
    }
    double getPerimeter() const override {
        return 2 * (length + width);
    }
};

int main() {
    // Create instances of Circle and Rectangle
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    // Calculate and display the area and perimeter of each shape
    cout << "Circle Area: " << circle.getArea() << ", Perimeter: " << circle.getPerimeter() << endl;
    cout << "Rectangle Area: " << rectangle.getArea() << ", Perimeter: " << rectangle.getPerimeter() << endl;

    return 0;
}
```

---

## Sample Output

When the program runs, it outputs:

```
Circle Area: 78.5398, Perimeter: 31.4159
Rectangle Area: 24, Perimeter: 20
```

### Explanation:
1. **Interface Definition**: The `Shape` class provides a structure with pure virtual functions.
2. **Implementation in Derived Classes**:
   - `Circle` and `Rectangle` provide specific implementations for `getArea()` and `getPerimeter()`.
3. **Interface Usage**: Objects of `Circle` and `Rectangle` call their own versions of the methods.

---

## Key Concepts

1. **Interfaces in C++**:
   - C++ does not have built-in interfaces like Java.
   - Achieved using abstract classes with pure virtual functions.

2. **Pure Virtual Functions**:
   - A function declared with `= 0` in a class.
   - Must be implemented by derived classes.

3. **Encapsulation and Code Reusability**:
   - The `Shape` interface ensures a common structure for different shapes.
   - Avoids duplicate code and enhances modularity.

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

This implementation demonstrates the use of **Interfaces in C++**, ensuring a flexible and reusable design pattern for different shapes.

