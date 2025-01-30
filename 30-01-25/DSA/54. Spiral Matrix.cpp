#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix[0].size();
        int n = matrix.size();
        int total = m*n;
        int count = 0;

        int left = 0,right = m-1;
        int top = 0,bottom = n-1;
        while(count < total){
            // left -> right
            for(int i = left;i<=right;i++){
                result.push_back(matrix[top][i]);
                count++;
            }
            top++;
            // top -> bottom
            for(int i = top;i<=bottom;i++){
                result.push_back(matrix[i][right]);
                count++;
            }
            right--;
            if(top<=bottom){
                // right -> left
                for(int i = right;i>=left;i--){
                    result.push_back(matrix[bottom][i]);
                    count++;
                }
                bottom--;
            }
            if(left<=right){
                // bottom -> top
                for(int i = bottom;i>=top;i--){
                    result.push_back(matrix[i][left]);
                    count++;
                }
                left++;
            }
        }
        return result;
    }
};