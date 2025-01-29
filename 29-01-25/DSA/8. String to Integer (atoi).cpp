#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int myAtoi(string s) {
        long long n = s.length();
        long long i = 0;
        long long ans = 0;
        int sign = 1;

        //check for whitespace
        while (i < n && s[i] == ' ')
        {
            i++;
        }
           
        //check for signedness   
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
           if(s[i]=='-') sign = -1;
           i++;
        }

        //conversion of number
        while (i < n && (s[i] >= '0' && s[i] <= '9'))
        {
            ans = ans*10 + (s[i] - '0');
            i++;

            //check for rounding  (INT_MIN <= ans <= INT_MAX)
            if (ans * sign > INT_MAX)
                return INT_MAX;
            if (ans * sign < INT_MIN)
                return INT_MIN;
        }

        ans *= sign;
        return ans;
    }
};