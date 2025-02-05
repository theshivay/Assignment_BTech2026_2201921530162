#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        int count = 0;
        int ind;
        for(int i = 0;i<s1.size();i++){
            if(s1[i] != s2[i] && count == 1){
                char temp = s2[i];
                s2[i] = s2[ind];
                s2[ind] = temp;
                break;
            }else if(s1[i] != s2[i]){
                count++;
                ind = i;
            }
        }
        if(s1 == s2) return true;
        return false; 
    }
};
// Approach : Dimag ka Dahi approach
// class Solution {
// public:
//     bool areAlmostEqual(string s1, string s2) {
//         if(s1.size() != s2.size()) return false;
//         int count = 0;
//         char fst;
//         char scd;
//         for(int i = 0;i<s1.size();i++){
//             if(s1[i] != s2[i] && count == 2){
//                 return false;
//             }else if(s1[i] != s2[i] && count == 1){
//                 count++;
//                 if(fst != s2[i]) return false;
//                 if(scd != s1[i]) return false;
//             }else if(s1[i] != s2[i]){
//                 count++;
//                 fst = s1[i];
//                 scd = s2[i];
//             }
//         }
//         if(count == 1) return false;

//         return true; 
//     }
// };