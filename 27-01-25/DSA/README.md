# 1. Two Sum - Leetcode

## Problem Statement
Given an array of integers `nums` and an integer `target`, return the indices of two numbers such that they add up to `target`. You may not use the same element twice.

### Example
**Input:**
```
nums = [2, 7, 11, 15], target = 9
```
**Output:**
```
[0, 1] (because nums[0] + nums[1] = 9)
```

---

## Platform
Solved on **Leetcode**: [Two Sum](https://leetcode.com/problems/two-sum/)

---

## Approach

### 1. Optimized (Hash Map)
- Use a hash map to store indices of numbers.
- For each number, check if `target - nums[i]` exists in the map.
- If found, return the indices; otherwise, add the number to the map.

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

**Code:**
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }
};
```

### 2. Brute Force
- Use two nested loops to find a pair that sums to `target`.

**Time Complexity:** O(n²)  
**Space Complexity:** O(1)

**Code:**
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
```

---

## Comparison
| **Approach**       | **Time** | **Space** | **Notes**            |
|--------------------|----------|-----------|----------------------|
| Optimized (Hash Map) | O(n)     | O(n)      | Efficient            |
| Brute Force         | O(n²)    | O(1)      | Simple but slower    |

---
###

# 13. Roman to Integer - Leetcode

## Problem Statement
Convert a Roman numeral string `s` to its integer equivalent. Roman numerals are represented by the following characters:
- `I = 1`, `V = 5`, `X = 10`, `L = 50`, `C = 100`, `D = 500`, `M = 1000`

In Roman numerals, smaller values preceding larger values are subtracted (e.g., IV = 4), while others are added (e.g., VI = 6).

### Example
**Input:**
```
s = "LVIII"
```
**Output:**
```
58 (L = 50, V = 5, III = 3)
```

---

## Platform
Solved on **Leetcode**: [Roman to Integer](https://leetcode.com/problems/roman-to-integer/)

---

## Approach

### Optimized Approach: Single Pass
**Algorithm:**
1. Create a mapping of Roman numeral characters to their integer values.
2. Iterate through the string in reverse order:
   - If the current numeral is smaller than the previous numeral, subtract it.
   - Otherwise, add it to the result.
3. Update the previous numeral value after each iteration.
4. Return the result.

**Time Complexity:** O(n) (Single traversal of the string)  
**Space Complexity:** O(1)

**Code:**
```c
int romanToInt(char* s) {
    int romanValues[] = {
        ['I'] = 1,
        ['V'] = 5,
        ['X'] = 10,
        ['L'] = 50,
        ['C'] = 100,
        ['D'] = 500,
        ['M'] = 1000
    };

    int result = 0;
    int prevValue = 0;

    for (int i = strlen(s) - 1; i >= 0; --i) {
        int currentValue = romanValues[s[i]];

        if (currentValue < prevValue) {
            result -= currentValue;
        } else {
            result += currentValue;
        }

        prevValue = currentValue;
    }

    return result;
}
```

---
###
# 20. Valid Parentheses - Leetcode

## Problem Statement
Given a string `s` containing just the characters `(`, `)`, `{`, `}`, `[` and `]`, determine if the input string is valid. A string is valid if:
- Open brackets are closed by the same type of brackets.
- Open brackets are closed in the correct order.

### Example
**Input:**
```
s = "()[]{}"
```
**Output:**
```
true
```

---

## Platform
Solved on **Leetcode**: [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)

---

## Approach

### Stack-based Approach
**Algorithm:**
1. Use a stack to store open brackets.
2. Traverse the string:
   - Push open brackets onto the stack.
   - If a closing bracket is encountered, check if it matches the top of the stack:
     - If it matches, pop the stack.
     - Otherwise, the string is invalid.
3. After traversal, the string is valid if the stack is empty.

**Time Complexity:** O(n) (Single traversal of the string)  
**Space Complexity:** O(n) (Space used by the stack)

**Code:**
```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else {
                if (stack.empty()) return false;
                char top = stack.top();
                if ((c == ')' && top == '(') || 
                    (c == '}' && top == '{') || 
                    (c == ']' && top == '[')) {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
        return stack.empty();
    }
};
```




