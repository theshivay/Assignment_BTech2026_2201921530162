#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int l = 0, r = height.size() - 1;
            int maxArea = 0;
            while ( l < r ){
                int area = height[l] < height[r] ? height[l] * (r-l) : height[r] * (r-l);
                if ( area > maxArea ){
                    maxArea = area;
                } 
            
                if ( height[l] < height[r]) l++;
                else r--;
                }
            return maxArea;
        }
    };

         // int small=0;
        // int max=0;
        // int ar=0;
        // for(int i=0;i<height.size()-1;i++){
        //     for(int j=i+1;j<height.size();j++){
        //         (height[i]>height[j])?(small=height[j]):(small=height[i]);
        //         ar=small*(j-i);
        //         if(ar>max){
        //             max=ar;
        //         }
        //     }
        // }
        // return max;
//     }
// };

// int maxArea(int* height, int heightSize){
//     int l = 0, r = heightSize - 1;
//     int maxArea = 0;
//     while ( l < r ){
//         int area = height[l] < height[r] ? height[l] * (r-l) : height[r] * (r-l);
//         if ( area > maxArea ){
//             maxArea = area;
//         } 
        
//         if ( height[l] < height[r]) l++;
//         else r--;
//     }
//     return maxArea;
// }