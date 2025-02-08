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