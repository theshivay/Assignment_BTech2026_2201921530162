#include <iostream>
using namespace std;

// Abstract class Vehicle
class Vehicle {
public:
    virtual void start() = 0;  // Pure virtual function
    virtual void stop() = 0;   // Pure virtual function
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
