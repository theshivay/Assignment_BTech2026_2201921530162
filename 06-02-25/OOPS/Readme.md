# 1. Vehicle Management System - Polymorphism in C++

## Overview
This project demonstrates **polymorphism** in C++ through a **Vehicle Management System**. It defines a base class `Vehicle` with derived classes `Car`, `Truck`, and `Motorcycle`, allowing uniform handling of different vehicle types through a common interface.

## Approach & Solution
- **Polymorphism**: Enables different vehicle types to implement their own behavior for common operations like `start()` and `stop()`.
- **Dynamic Method Dispatch**: Ensures the appropriate method is executed at runtime based on the object type.
- **Extensibility**: New vehicle types can be added without modifying existing code.

## Code
```cpp
#include <iostream>
using namespace std;

// Abstract class Vehicle
class Vehicle {
public:
    virtual void start() = 0; // Pure virtual function
    virtual void stop() = 0;  // Pure virtual function
};

// Derived classes implementing Vehicle
class Car : public Vehicle {
public:
    void start() override { cout << "Starting the car engine." << endl; }
    void stop() override { cout << "Stopping the car engine." << endl; }
};

class Truck : public Vehicle {
public:
    void start() override { cout << "Starting the truck engine." << endl; }
    void stop() override { cout << "Stopping the truck engine." << endl; }
};

class Motorcycle : public Vehicle {
public:
    void start() override { cout << "Starting the motorcycle engine." << endl; }
    void stop() override { cout << "Stopping the motorcycle engine." << endl; }
};

// Main function
int main() {
    Vehicle* vehicle;
    Car car;
    Truck truck;
    Motorcycle motorcycle;

    vehicle = &car;
    vehicle->start();
    vehicle->stop();

    vehicle = &truck;
    vehicle->start();
    vehicle->stop();

    vehicle = &motorcycle;
    vehicle->start();
    vehicle->stop();

    return 0;
}
```

## Sample Output
```
Starting the car engine.
Stopping the car engine.
Starting the truck engine.
Stopping the truck engine.
Starting the motorcycle engine.
Stopping the motorcycle engine.
```

## How to Run
1. Copy the code into `vehicle_management.cpp`.
2. Compile the file:
   ```bash
   g++ vehicle_management.cpp -o vehicle_management
   ```
3. Run the compiled file:
   ```bash
   ./vehicle_management
   ```

## Conclusion
This project effectively demonstrates **polymorphism** by providing a uniform interface for different vehicle types. It enhances code maintainability, scalability, and flexibility by allowing easy integration of new vehicle classes.

