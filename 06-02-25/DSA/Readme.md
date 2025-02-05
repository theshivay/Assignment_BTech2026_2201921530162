# 1790. Check if One String Swap Can Make Strings Equal - Leetcode

## Problem Statement
Given two strings `s1` and `s2` of equal length, determine if one swap of two characters in `s2` can make it equal to `s1`.

## Coding Platform
- Leetcode

## Approach & Solution
1. If `s1` and `s2` are already equal, return `true`.
2. Traverse both strings and identify indices where characters differ.
3. If there are more than two mismatches, return `false`.
4. If exactly two mismatches exist, check if swapping those two characters in `s2` makes it equal to `s1`.
5. Otherwise, return `false`.

## Code Implementation
```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        int count = 0;
        int ind;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] != s2[i] && count == 1) {
                char temp = s2[i];
                s2[i] = s2[ind];
                s2[ind] = temp;
                break;
            } else if(s1[i] != s2[i]) {
                count++;
                ind = i;
            }
        }
        return s1 == s2;
    }
};
```

## Complexity Analysis
- **Time Complexity**: O(n) (single pass through the strings)
- **Space Complexity**: O(1) (constant space used)

---
###
# 82. Remove Duplicates from Sorted List II - Leetcode

## Problem Statement
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

## Coding Platform
- Leetcode

## Approach & Solution
1. Create a dummy node pointing to the head to handle edge cases smoothly.
2. Use two pointers: `prev` (points to the last unique node) and `current` (iterates through the list).
3. If duplicates are found, skip all occurrences and update `prev->next`.
4. If no duplicate is found, move `prev` forward.
5. Continue iterating until the end of the list.
6. Return the modified list starting from `dummy->next`.

**Code:**
```cpp
#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* current = head;

        while(current){
            bool dup = false;

            while(current->next && current->val == current->next->val){
                current = current->next;
                dup = true;
            }

            if(dup){
                prev->next = current->next;
            }else{
                prev = prev->next;
            }

            current = current->next;
        }
        return dummy->next;
    }
};
```

## Complexity Analysis
- **Time Complexity**: O(n) (single pass through the list)
- **Space Complexity**: O(1) (modifying the list in place)

---
###
# 402. Remove K Digits - Leetcode  

## Problem Statement  
Given a string `num` representing a non-negative integer and an integer `k`, remove `k` digits from `num` so that the remaining number is the smallest possible.  

## Coding Platform  
- Leetcode  

## Approach & Solution  
1. Use a stack to maintain the smallest possible number.  
2. Traverse the digits of `num`, and whenever a larger digit is found, remove the previous larger digit (if `k > 0`).  
3. If `k` remains, remove the last `k` digits.  
4. Construct the final number by skipping leading zeros.  
5. If the result is empty, return `"0"`.  


**Code:**
```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size()) return "0";

        string ans;
        vector<char> stack;

        for (int i = 0; i < num.length(); ++i) {
            while (k > 0 && !stack.empty() && stack.back() > num[i]) {
                stack.pop_back();
                --k;
            }
            stack.push_back(num[i]);
        }

        while (k-- > 0) stack.pop_back();

        for (const char c : stack) {
            if (c == '0' && ans.empty())
                continue;
            ans += c;
        }

        return ans.empty() ? "0" : ans;
    }
};
```


## Complexity Analysis  
- **Time Complexity**: O(n), as each digit is processed at most twice.  
- **Space Complexity**: O(n), for storing the stack.  

