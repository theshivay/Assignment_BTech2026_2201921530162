# 1. Rectangle Area - HackerRank 

## Problem Statement
Create two classes:
1. `Rectangle` with attributes `width` and `height` and a method `display()` that prints these values.
2. `RectangleArea` which inherits `Rectangle`, contains a method `read_input()` to read values, and overrides `display()` to print the area.

### Example
#### Input:
```
4 5
```
#### Output:
```
4 5
20
```

---

## Platform
Solved on **HackerRank**: [Rectangle Area](https://www.hackerrank.com/)

---

## Approach
1. Create a base class `Rectangle` with `width`, `height`, and `display()`.
2. Create a derived class `RectangleArea` that inherits `Rectangle`.
3. Implement `read_input()` in `RectangleArea` to read values from input.
4. Override `display()` in `RectangleArea` to print the area.
5. Use a `RectangleArea` object to read, display dimensions, and print the area.

---

## C++ Solution
```cpp
#include <iostream>
using namespace std;

class Rectangle {
public:
    int width, height;
    void display() {
        cout << width << " " << height << endl;
    }
};

class RectangleArea : public Rectangle {
public:
    void read_input() {
        cin >> width >> height;
    }
    void display() {
        cout << width * height << endl;
    }
};

int main() {
    RectangleArea r_area;
    r_area.read_input();
    r_area.Rectangle::display();
    r_area.display();
    return 0;
}
```

---


