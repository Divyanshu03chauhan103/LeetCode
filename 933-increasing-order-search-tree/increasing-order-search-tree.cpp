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
    void solve(TreeNode* root, vector<int>&values){
        if(!root) return;

        values.push_back(root->val);
        solve(root->left,values);
        solve(root->right,values);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>values;
        solve(root,values);
        sort(values.begin(),values.end());
        TreeNode* root1 = new TreeNode(values[0]);
        TreeNode* traversal=root1;
        for(int i=1;i<values.size();i++){
            TreeNode* curr=new TreeNode(values[i]);
            traversal->right=curr;
            traversal=traversal->right;
        }
        return root1;
    }   
};