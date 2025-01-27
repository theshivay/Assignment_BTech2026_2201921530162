#include<bits/stdc++.h>
using namespace std;

int romanToInt(char* s) {
    int romanValues[] = {
        ['I'] = 1,
        ['V'] = 5,
        ['X'] = 10,
        ['L'] = 50,
        ['C'] = 100,
        ['D'] = 500,
        ['M'] = 1000
    };

    int result = 0;
    int prevValue = 0;

    for (int i = strlen(s) - 1; i >= 0; --i) {
        int currentValue = romanValues[s[i]];

        if (currentValue < prevValue) {
            result -= currentValue;
        } else {
            result += currentValue;
        }

        prevValue = currentValue;
    }

    return result;
}