#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(const string &a,const string &b){
        return a + b < b + a;
    }
    string largestNumber(vector<int>& nums) {
        // Space O(n)
        vector<string> temp;
        // Time O(n)
        for(int i = 0;i<nums.size();i++) temp.push_back(to_string(nums[i]));
        // Time O(nlogn)
        sort(temp.begin(),temp.end(),cmp);
        if(temp[nums.size()-1] == "0") return "0";
        string result = "";
        // Time O(n)
        for(int i = temp.size()-1;i>=0;i--){
            result+=temp[i];
        }
        return result;
    }
};