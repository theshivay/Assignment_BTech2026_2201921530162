#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int result = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            int sum = nums[i];
            for(int j = i+1;j<nums.size();j++){
                if(nums[j-1]<nums[j]){
                    sum+=nums[j];
                }else break;
            }
            result = max(result,sum);
        }
        return result;
    }
};