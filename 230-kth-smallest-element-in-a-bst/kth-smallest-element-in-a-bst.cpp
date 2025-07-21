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
    void inorderplus(TreeNode* root, int k, int& count, int &ans) {
        if(!root) return; 
        inorderplus(root->left, k, count, ans); 
        count++; 
        if(count == k) ans = root->val; 
        inorderplus(root->right, k, count, ans); 

    }
    int kthSmallest(TreeNode* root, int k) {    
        int ans; 
        int count = 0; 
        inorderplus(root, k, count, ans);
        return ans; 
    }
};