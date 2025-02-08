# Inheritance in Real-World Industries

## Concept of Inheritance  
Inheritance is an **Object-Oriented Programming (OOP)** principle that allows one class to derive properties and behaviors from another class. It promotes **code reusability**, **scalability**, and **maintainability** in software development.  

### Real-World Industry Example: **Automobile Manufacturing**  
In the automobile industry, different types of vehicles share common characteristics like **engine, wheels, and fuel capacity** but have distinct features like **speed, fuel type, and design**. Instead of rewriting code for each vehicle type, we use **inheritance** to define a **base class** (`Vehicle`) and derive multiple **subclasses** (`Car`, `Bike`, `Truck`).  

---

## Approach & Solution  
1. Define a **base class** `Vehicle` that contains common properties (`brand`, `speed`, `fuelType`) and a method `displayDetails()`.  
2. Create **derived classes** (`Car`, `Bike`, `Truck`) that inherit from `Vehicle` and extend functionalities.  
3. Use an **object-oriented approach** to create specific vehicle instances and display their details.  

---

## C++ Implementation  

```cpp
#include <iostream>
using namespace std;

// Base class: Vehicle
class Vehicle {
public:
    string brand;
    int speed;
    string fuelType;

    Vehicle(string b, int s, string f) : brand(b), speed(s), fuelType(f) {}

    void displayDetails() {
        cout << "Brand: " << brand << ", Speed: " << speed << " km/h, Fuel Type: " << fuelType << endl;
    }
};

// Derived class: Car
class Car : public Vehicle {
public:
    int doors;

    Car(string b, int s, string f, int d) : Vehicle(b, s, f), doors(d) {}

    void showCarDetails() {
        displayDetails();
        cout << "Doors: " << doors << endl;
    }
};

// Derived class: Bike
class Bike : public Vehicle {
public:
    bool hasGear;

    Bike(string b, int s, string f, bool g) : Vehicle(b, s, f), hasGear(g) {}

    void showBikeDetails() {
        displayDetails();
        cout << "Has Gear: " << (hasGear ? "Yes" : "No") << endl;
    }
};

int main() {
    Car car1("Toyota", 180, "Petrol", 4);
    Bike bike1("Yamaha", 120, "Petrol", true);

    cout << "Car Details:" << endl;
    car1.showCarDetails();

    cout << "\nBike Details:" << endl;
    bike1.showBikeDetails();

    return 0;
}
```

---

## Complexity Analysis  

- **Time Complexity**: O(1) → Each function runs in constant time as they only access and display attributes.  
- **Space Complexity**: O(1) → Uses only a few class instances without significant memory overhead.  

---
