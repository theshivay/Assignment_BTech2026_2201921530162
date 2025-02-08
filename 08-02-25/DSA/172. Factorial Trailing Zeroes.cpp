#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        if(n<5) return 0;
        int count = 0;
        for(int i = 1;n/pow(5,i)>0;i++){
            int digit = n/pow(5,i);
            count+=digit;
        }
        return count;
    }
};