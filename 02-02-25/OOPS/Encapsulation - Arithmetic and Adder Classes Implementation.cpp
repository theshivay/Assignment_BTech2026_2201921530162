#include <iostream>
using namespace std;

// Base class implementing encapsulation
class Arithmetic {
private:
    int sum;

public:
    // Method to add two integers and store the result
    void add(int n1, int n2) {
        sum = n1 + n2;
    }
    
    // Getter method to retrieve the sum
    int getSum() {
        return sum;
    }
};

// Subclass
class Adder : public Arithmetic {
    // No additional methods or properties required
};

// Main function
int main() {
    // Create an Adder object
    Adder adder;
    
    // Perform addition operations
    adder.add(10, 32);
    cout << "Sum: " << adder.getSum() << endl;
    
    adder.add(10, 3);
    cout << "Sum: " << adder.getSum() << endl;
    
    adder.add(10, 10);
    cout << "Sum: " << adder.getSum() << endl;
    
    return 0;
}