#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> stack;
        for(int i =0;i<s.size();i++){
            if(stack.empty()){
                stack.push(s[i]);
            }
            else if(stack.top()=='('){
                if(s[i]==')'){
                    stack.pop();
                }
                else{
                    stack.push(s[i]);
                }
            }
            else if(stack.top()=='{'){
                if(s[i]=='}'){
                    stack.pop();
                }
                else{
                    stack.push(s[i]);
                }
            }
            else if(stack.top()=='['){
                if(s[i]==']'){
                    stack.pop();
                }
                else{
                    stack.push(s[i]);
                }
            }
        }
        // if(stack.empty()){
        //     return true;
        // }
        // return false;
        return stack.empty();
    }
};