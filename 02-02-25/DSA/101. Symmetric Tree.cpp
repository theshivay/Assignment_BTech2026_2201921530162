#include<bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    void Symmetric(TreeNode * root1,TreeNode * root2,bool &res){

        if(root1==NULL && root2==NULL){
            return;
        }

        if(root1==NULL || root2==NULL || root1->val!=root2->val){
            res=false;
            return;
        }
        Symmetric(root1->left,root2->right,res);
        Symmetric(root1->right,root2->left,res);
    }

    bool isSymmetric(TreeNode* root) {
        bool res=true;
        Symmetric(root->left,root->right,res);
        return res;
    }
};