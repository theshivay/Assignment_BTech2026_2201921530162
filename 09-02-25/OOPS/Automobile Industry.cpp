#include <iostream>
using namespace std;

// Abstract class
class Car {
public:
    virtual void startEngine() = 0;  // Pure virtual function
    virtual void stopEngine() = 0;   // Pure virtual function
};

// Concrete class
class Tesla : public Car {
public:
    void startEngine() override {
        cout << "Tesla's electric engine started!" << endl;
    }
    void stopEngine() override {
        cout << "Tesla's engine stopped!" << endl;
    }
};

int main() {
    Car* myCar = new Tesla();
    myCar->startEngine();
    myCar->stopEngine();
    delete myCar;
    return 0;
}