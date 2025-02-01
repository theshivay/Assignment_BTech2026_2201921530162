# 3151. Special Array I - Leetcode 

## Problem Statement
Given an integer array `nums`, determine if it is **special**. An array is special if no two adjacent elements have the same parity (even or odd).

### Example:
**Input:** `nums = [1, 2, 3, 4]`  
**Output:** `true`

**Input:** `nums = [2, 4, 6]`  
**Output:** `false`

---

## Platform
Solved on **Leetcode**: [Special Array I](https://leetcode.com/problems/special-array-i/)

---

## Approach

1. Traverse the array and check adjacent elements.
2. If two consecutive elements have the same parity (`both even` or `both odd`), return `false`.
3. If no such case is found, return `true`.

### Code:
```cpp
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] % 2 == nums[i+1] % 2) return false;
        }
        return true;
    }
};
```

**Time Complexity:** O(n) (Single pass through the array)  
**Space Complexity:** O(1) (Constant extra space)  

---
###
# 58. Length of Last Word - Leetcode

## Problem Statement
Given a string `s` consisting of words and spaces, return the length of the last word in the string. A word is defined as a maximal substring consisting of non-space characters only.

### Example:
**Input:** `s = "Hello World"`  
**Output:** `5`

---

## Platform
Solved on **Leetcode**: [Length of Last Word](https://leetcode.com/problems/length-of-last-word/)

---

## Approach

### Iterating from the End
**Algorithm:**
1. Start iterating from the end of the string.
2. Skip trailing spaces.
3. Count characters until a space is encountered.
4. Return the count.

**Code:**
```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int count = 0;
        for(int i = n - 1; i >= 0; i--) {
            if (count > 0 && s[i] == ' ') {
                break;
            }
            else if (s[i] != ' ') {
                count++;
            }
        }
        return count;
    }
};
```

**Time Complexity:** O(n) (Iterating through the string once)  
**Space Complexity:** O(1) (Constant space usage)  

---
###

# 67. Add Binary - Leetcode

## Problem Statement
Given two binary strings `a` and `b`, return their sum as a binary string.

### Example:
**Input:** `a = "11"`, `b = "1"`  
**Output:** `"100"`

---

## Platform
Solved on **Leetcode**: [Add Binary](https://leetcode.com/problems/add-binary/)

---

## Approach

### Simulation of Binary Addition
**Algorithm:**
1. Initialize an empty result string `res` and a carry variable set to `0`.
2. Iterate from the last character of both strings (`i` for `a` and `j` for `b`).
3. Compute the sum of corresponding digits along with the carry.
4. Store the binary digit (`sum % 2`) in `res` and update the carry (`sum / 2`).
5. If any carry remains after iteration, append it to `res`.
6. Reverse the result string to get the final binary sum.

**Code:**
```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        while(i >= 0 || j >= 0){
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            carry = sum > 1 ? 1 : 0;
            res += to_string(sum % 2);
        }
        if(carry) res += to_string(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};
```

**Time Complexity:** O(N) (Iterating through both strings once)  
**Space Complexity:** O(1) (Reusing existing space, except for output string)

---