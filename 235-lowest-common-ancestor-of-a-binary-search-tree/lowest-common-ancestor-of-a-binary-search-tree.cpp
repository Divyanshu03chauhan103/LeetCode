/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root) return root;

        if(p->val>=root->val && q->val <=root->val)
            return root;
        if(p->val<=root->val && q->val >=root->val)
            return root;
        
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        if(left) return left;
        return lowestCommonAncestor(root->right,p,q);
    }
};