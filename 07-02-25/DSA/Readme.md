# 201. Bitwise AND of Numbers Range - Leetcode

## Problem Statement
Given two integers `m` and `n` where `0 <= m <= n`, return the bitwise AND of all numbers in the range `[m, n]`.

## Coding Platform
- Leetcode

## Approach & Solution
1. Instead of iterating from `m` to `n` and computing the AND operation, an optimized approach is used.
2. Keep right shifting both `m` and `n` until they become equal.
3. Count the number of shifts performed.
4. Left shift the final result by the count to restore the original bit positions.

**Code:**
```cpp
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count=0;
        while(m!=n){  // See till both numbers are equal
            m>>=1;   // Right shift both numbers by 1
            n>>=1;
            count++;  // Increment the count
        }
        return m<<count; // Left shift m by count to restore bits
    }
};
```

## Complexity Analysis
- **Time Complexity**: O(log n) (as the numbers are right-shifted until they become equal)
- **Space Complexity**: O(1) (only a few integer variables are used)

---
###

# 202. Happy Number - Leetcode

## Problem Statement
A number is called **happy** if repeatedly replacing it with the sum of the squares of its digits eventually results in `1`. If it enters a cycle instead, it is not a happy number.

## Coding Platform
- Leetcode

## Approach & Solution
1. Use a **set** to track previously seen numbers to detect cycles.
2. Define a recursive function to:
   - Compute the sum of the squares of the digits of `n`.
   - Check if the result is `1` (happy number) or if it repeats (unhappy number).
3. Base case: If `n == 1`, return `true`.
4. If the number repeats (exists in the set), return `false`.

**Code:**
```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<int> s;
    int count = 0;

    int recursion(int n){
        if(n == 1)
            return 1;

        s.insert(n);
        count++;

        if(s.size() != count)
            return 0;

        int sum = 0;
        while(n!=0){
            int digit = n%10;
            sum += digit*digit;
            n = n/10;
        }
        return recursion(sum);
    }

    bool isHappy(int n) {
        return recursion(n);
    }
};
```

## Complexity Analysis
- **Time Complexity**: O(log n) (Each number reduces significantly with digit square sum)
- **Space Complexity**: O(log n) (Set stores previously seen numbers)

---
###

# 1726. Tuple with Same Product - Leetcode

## Problem Statement
Given an array `nums` of distinct positive integers, return the number of tuples `(a, b, c, d)` such that `a * b = c * d` and `(a, b, c, d)` are distinct indices.

## Coding Platform
- Leetcode

## Approach & Solution
1. Use a hash map to store the product of pairs and their occurrence count.
2. Iterate through all possible pairs `(i, j)` in the array.
3. If the product has been seen before, increase the count using the formula `8 * previous_count`.
4. Store/update the count of each product in the hash map.
5. Return the final count.

**Code:**
```cpp
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
        return count;
    }
};
```

## Complexity Analysis
- **Time Complexity**: O(n^2) (nested loop for pairwise multiplication)
- **Space Complexity**: O(n^2) (hash map storage for products)

