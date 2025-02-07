#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int count = 0;
        map<long long, long long> hs;
        
        for(int i = 0;i<nums.size() - 1;i++){
            for(int j = i+1;j<nums.size();j++){
                count+= 8 * (hs[nums[i]*nums[j]]);
                hs[nums[i]*nums[j]]++;
            }
        }

        // for(auto it : hs){
        //     if(it.second >=2){
        //         count+=(8 * (it.second - 1));
        //     }
        // }
        return count;
    }
};