#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        sort(nums.begin(), nums.end());
        int count = 1, value = 0, n = nums.size();
        for(int i = 1; i < n; ++i){
            if(nums[i] == nums[i - 1]){
                ++count;
                if(count > (n / 2)){
                    value = nums[i];
                    break;
                }
            }
        }
        return value;
    }
};