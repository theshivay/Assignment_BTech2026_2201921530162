# Problem: C++ Interface - Advanced Arithmetic

### Problem Description:
You are asked to implement a class `MyCalculator` that implements the `AdvancedArithmetic` interface. This interface contains a method signature `int divisor_sum(int n)`. The goal is to compute the sum of divisors of a given integer `n`.

For example:
- Divisors of 6 are 1, 2, 3, and 6, so the sum is 12.
- Divisors of 12 are 1, 2, 3, 4, 6, and 12, so the sum is 28.

The value of `n` will be at most 1000.

### Requirements:
1. Implement the method `divisor_sum(int n)` in the `MyCalculator` class to return the sum of divisors of the integer `n`.
2. The `divisor_sum` method should take an integer and return the sum of all its divisors.
3. The class `MyCalculator` should implement the `AdvancedArithmetic` interface.

### Solution:
The `MyCalculator` class implements the `AdvancedArithmetic` interface, and the `divisor_sum(int n)` method calculates the sum of divisors by iterating through all integers from 1 to `n` and checking if they divide `n` without leaving a remainder. If they do, they are added to the sum.

### C++ Code:
```cpp
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
```

### Sample Input and Output:

**Sample Input:**
```
6
```

**Sample Output:**
```
I implemented: AdvancedArithmetic
12
```

### Explanation:
- Divisors of 6 are 1, 2, 3, and 6. The sum of these divisors is `1 + 2 + 3 + 6 = 12`. Therefore, the output is 12.

