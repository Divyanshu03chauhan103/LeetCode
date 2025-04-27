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
    int solve(TreeNode* root,int curr){
        if(!root) return 0;
        int add = (root->val>=curr)? 1 : 0;
        int left =solve(root->left,max(root->val,curr));
        int right = solve(root->right,max(root->val,curr));
        return left + right+add;
    }

    int goodNodes(TreeNode* root) {
        return solve(root, root->val);
    }
};
