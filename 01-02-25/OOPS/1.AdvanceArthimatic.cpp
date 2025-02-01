#include <iostream>
using namespace std;

class AdvancedArithmetic {
public:
    virtual int divisor_sum(int n) = 0;
};

class MyCalculator : public AdvancedArithmetic {
public:
    int divisor_sum(int n) override {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                ans += i;
            }
        }
        return ans;
    }
};

int main() {
    MyCalculator my_calculator;
    cout << "I implemented: AdvancedArithmetic" << endl;
    int n;
    cin >> n;
    cout << my_calculator.divisor_sum(n) << endl;
    return 0;
}
