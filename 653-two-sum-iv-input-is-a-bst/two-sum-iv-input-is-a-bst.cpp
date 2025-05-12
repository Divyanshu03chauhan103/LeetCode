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
    bool solve(unordered_map<int,int>&mp,TreeNode* root,int k){

        if(!root){
            return false;
        }
        
        if(mp.find(k-root->val)!=mp.end()) return true;

        mp[root->val]++;
       return  solve(mp,root->left,k) ||
        solve(mp,root->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
        
        unordered_map<int,int>mp;

        return solve(mp,root,k);

    }
};