#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices){
         int ans = 0;
        int minValue = prices[0];
        for(int i=1; i<prices.size();i++){
            int tmpSum = prices[i] - minValue;
            if(tmpSum > ans)
                ans = tmpSum;
            if(prices[i]<minValue)
                minValue = prices[i];
        }
        return ans;
    }
};