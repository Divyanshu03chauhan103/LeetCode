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
    int solve(TreeNode* root,int &result){
        if(!root) return 0;

        int left_sum=solve(root->left,result);
        int right_sum=solve(root->right,result);
        
        result+=abs(left_sum-right_sum);

        return left_sum+right_sum+root->val;
    }
    int findTilt(TreeNode* root) {
        
        int result=0;
        solve(root,result);
        return result;
    }
};