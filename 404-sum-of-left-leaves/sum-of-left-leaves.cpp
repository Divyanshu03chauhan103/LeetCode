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
    int solve(TreeNode* root,bool isLeft){

        if(!root) return 0;

        if(isLeft && !root->left && !root->right){
            return root->val;
        }

        int left_max = solve(root->left,true);
        int right_max=solve(root->right,false);
        return left_max+right_max;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        
        return solve(root,false);
         
    }
};