#include <iostream>
using namespace std;

class BiCycle {
public:
    string define_me() {
        return "a vehicle with pedals.";
    }
};

class MotorCycle : public BiCycle {
public:
    string define_me() {
        return "a cycle with an engine.";
    }
    
    MotorCycle() {
        cout << "Hello I am a motorcycle, I am " << define_me() << endl;
        
        string temp = BiCycle::define_me(); // Using scope resolution to call base class method
        cout << "My ancestor is a cycle who is " << temp << endl;
    }
};

int main() {
    MotorCycle M;
    return 0;
}