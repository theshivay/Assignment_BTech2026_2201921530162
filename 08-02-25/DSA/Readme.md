# 2349. Design a Number Container System - Leetcode

## Problem Statement
Design a system that allows you to assign numbers to indices and efficiently retrieve the smallest index for a given number.

## Coding Platform
- Leetcode

## Approach & Solution
1. Use two hash maps:
   - `mp1` to store the mapping of index to number.
   - `mp2` to store a set of indices for each number, allowing quick access to the smallest index.
2. When `change(index, number)` is called:
   - If the index is already assigned a number, remove it from the previous set.
   - Add the index to the set of the new number.
3. When `find(number)` is called:
   - Return the smallest index from the set, or `-1` if the number is not present.

**Code:**
```cpp
#include<bits/stdc++.h>
using namespace std;

class NumberContainers {
    unordered_map<int, int> mp1;
    unordered_map<int, set<int>> mp2;

public:
    NumberContainers() {}

    void change(int index, int number) {
        if (mp1.find(index) != mp1.end()){
            int num = mp1[index];
            mp2[num].erase(index);
            if (mp2[num].empty()) {
                mp2.erase(num);
            }
        }
        mp2[number].insert(index);
        mp1[index] = number;
    }

    int find(int number) {
        if (mp2.find(number) != mp2.end() && !mp2[number].empty())
            return *mp2[number].begin();
        else
            return -1;
    }
};
```

## Complexity Analysis
- **Time Complexity**:
  - `change()`: O(log n) (insertion/removal in a set)
  - `find()`: O(1) (accessing the smallest element in a set)
- **Space Complexity**: O(n) (storage for indices and mappings)

---
###
# 172. Factorial Trailing Zeroes - Leetcode

## Problem Statement
Given an integer `n`, return the number of trailing zeroes in `n!` (n factorial).  

## Coding Platform
- Leetcode  

## Approach & Solution
1. A trailing zero is created by the factor `10`, which is the product of `2` and `5`.
2. Since there are always more factors of `2` than `5`, count the number of `5`s in the factorization of `n!`.
3. The number of times `5` appears as a factor is calculated using `n / 5 + n / 25 + n / 125 + ...` until `n / 5^i` is zero.
4. Return the total count of `5`s.

**Code:**
```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        if(n < 5) return 0;
        int count = 0;
        for(int i = 1; n / pow(5, i) > 0; i++){
            count += n / pow(5, i);
        }
        return count;
    }
};
```

## Complexity Analysis
- **Time Complexity**: O(log n) (dividing `n` by powers of 5)
- **Space Complexity**: O(1) (constant extra space)

---
###
# 200. Number of Islands - Leetcode

## Problem Statement
Given a 2D grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are surrounded by water.

## Coding Platform
- Leetcode

## Approach & Solution
1. Iterate through the grid and look for land ('1').
2. When land is found, initiate a Depth-First Search (DFS) to mark all connected land as visited by changing it to '0'.
3. Recursively explore all four possible directions (up, down, left, right) until the island is fully traversed.
4. Increase the island count and continue scanning the grid.
5. Return the total number of islands found.

**Code:**
```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid,int r,int c,int m,int n){
        if (r<0 || r==m || c<0 || c==n || grid[r][c]=='0') return;
        grid[r][c]='0';
        dfs(grid,r+1,c,m,n);
        dfs(grid,r-1,c,m,n);
        dfs(grid,r,c-1,m,n);
        dfs(grid,r,c+1,m,n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j,m,n);
                    ans+=1;
                }
            }
        }
        return ans;
    }
};
```

## Complexity Analysis
- **Time Complexity**: O(m * n) (each cell is visited once and explored in four directions)
- **Space Complexity**: O(m * n) (recursive DFS stack depth in the worst case)

