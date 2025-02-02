#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int count  = 0;
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                count = i+1;
            }
        }

        int n = nums.size()-1;
        while(n--){
            if(nums[(count) % nums.size()] > nums[(count+1) % nums.size()]) return false;
            count++;
        }

        return true;
    }
};