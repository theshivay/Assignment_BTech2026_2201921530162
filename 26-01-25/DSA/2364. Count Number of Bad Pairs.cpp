#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            unordered_map<long, int> hs;
            long long n = nums.size();
            
            for (long i = 0; i < n; i++) {
                hs[nums[i] - i]++;
            }
            
            long long goodPairs = 0;
            for (auto &i : hs) {
                long long s = i.second;
                goodPairs += (s - 1) * s / 2;
            }
            
            return n * (n - 1) / 2 - goodPairs;
        }
    };
    
    // Approach : Brute Force
    // class Solution {
    // public:
    //     long long countBadPairs(vector<int>& nums) {
    //         long long count  = 0;
    //         for(int i = 0;i<nums.size();i++){
    //             for(int j = i+1;j<nums.size();j++){
    //                 if(j - i != nums[j] - nums[i]) count++;
    //             }
    //         }
    
    //         return count;
    //     }
    // };