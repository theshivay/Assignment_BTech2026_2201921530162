#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {   
        string res = "";

        while(columnNumber) {
            columnNumber--;
            char current = 'A' + columnNumber % 26;
            res += current;
            columnNumber /= 26;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};