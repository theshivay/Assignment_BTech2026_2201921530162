#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    unordered_set <int> s;
    int count = 0;

    int recursion(int n){
        if(n == 1)
            return 1;

        s.insert(n);
        count++;

        if(s.size() != count)
            return 0;

        int sum = 0;
        while(n!=0){
            int digit = n%10;
            sum += digit*digit;
            n = n/10;
        }
        return recursion(sum);
    }

    bool isHappy(int n) {
        return recursion(n);
    }
};