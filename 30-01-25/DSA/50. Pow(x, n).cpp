#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1)
            return 1;
        
        double val = myPow(x, n / 2);
        val *= val;
        
        if (n % 2 == 0)
            return val;
        
        return (n < 0) ? val * (1 / x) : val * x;
    }
};