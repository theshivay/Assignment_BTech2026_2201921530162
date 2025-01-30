# 1. Abstract Class --

## Problem Description
In C++, an abstract class cannot be instantiated directly. It serves as a base class for other classes to inherit from. The objective is to create a class that extends an abstract class and implements the required pure virtual methods.

### Abstract Class: `Book`

```cpp
class Book {
protected:
    string title;
public:
    virtual void setTitle(string s) = 0; // Pure virtual function
    string getTitle() {
        return title;
    }
};
```

- The `Book` class has a pure virtual method `setTitle` which must be implemented in a derived class.
- The `getTitle` method returns the title of the book.

### Task
You are required to implement the `MyBook` class that extends the abstract `Book` class and provides the implementation for the `setTitle` method.

### Solution

```cpp
class MyBook : public Book {
public:
    void setTitle(string s) override {
        title = s;
    }
};
```

### Explanation:
- The `MyBook` class inherits from the `Book` class and implements the `setTitle` method.
- The `setTitle` method assigns the input string to the `title` attribute.

### Sample Input

```
A Tale of Two Cities
```

### Sample Output

```
The title is: A Tale of Two Cities
```

---

