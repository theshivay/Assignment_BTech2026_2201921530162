#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string clearDigits(string s) {
            stack<char> ch;
            for(int i = 0;i<s.size();i++){
                if(s[i] >= '0' && s[i]<='9'){
                    if(!ch.empty()) ch.pop();
                }else{
                    ch.push(s[i]);
                }
            }
            string result = "";
            while(!ch.empty()){
                result = ch.top() + result;
                ch.pop();
    
            }
            return result;
        }
    };