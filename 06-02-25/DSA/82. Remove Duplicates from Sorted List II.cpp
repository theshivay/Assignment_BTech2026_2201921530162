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