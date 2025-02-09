#include<bits/stdc++.h>
using namespace std;


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> alpha(128, -1); // Stores last seen index of character
        int start = 0, result = 0;

        for (int i = 0; i < s.size(); i++) {
            if (alpha[s[i]] >= start) { // If character is inside current window
                start = alpha[s[i]] + 1; // Move start pointer
            }
            alpha[s[i]] = i; // Update last seen index
            result = max(result, i - start + 1); // Update max length
        }
        return result;
    }
};
    
    
    
    
    // class Solution {
    // public:
    //     int lengthOfLongestSubstring(string s) {
    //         int result = 0;
    //         if(s.size()<2){
    //             return s.size();
    //         }
    //         int n;
    //         for(int i = 0; i < s.size() - 1; i++) {
    //             string str = "";
    //             str += s[i];
    //             for(int j = i + 1; j < s.size(); j++) {
    //                 if (str.find(s[j]) != string::npos) {
    //                     n = str.size();
    //                     result = max(result, n);
    //                     break;
    //                 } else {
    //                     str += s[j];
    //                     n = str.size();
    //                     result = max(result, n);
    //                 }
    //             }
    //         }
    //         return result;
    //     }
    // };
    