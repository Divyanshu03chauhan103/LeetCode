/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        return isValid(root,LLONG_MIN,LLONG_MAX);
    }

    bool isValid(TreeNode* root,long long lower,long long higher){
        if(!root) return true;

        if(root->val<=lower || root->val>=higher) return false;

        if(!(isValid(root->left,lower,root->val))|| !(isValid(root->right,root->val,higher))) return false;

        return true;
    }
};