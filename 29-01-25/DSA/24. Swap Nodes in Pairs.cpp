#include<bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* ptr = head;
        
        while (ptr != nullptr && ptr->next != nullptr) {
            int temp = ptr->val;
            ptr->val = ptr->next->val;
            ptr->next->val = temp;
            
            ptr = ptr->next->next;
        }
        
        return head;
    }
};