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
    void solve(vector<int>&values,TreeNode* root){

        if(!root) return;

        values.push_back(root->val);
        solve(values,root->left);
        solve(values,root->right);
            }

    int getMinimumDifference(TreeNode* root) {
        
        vector<int>values;
        solve(values,root);
        sort(values.begin(),values.end());

        int result=INT_MAX;
        for(int i=1;i<values.size();i++){
            result=min(values[i]-values[i-1],result);
        }
        return result;
    }
};