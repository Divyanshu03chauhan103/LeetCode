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
    void solve(unordered_map<int,int>&mp,TreeNode* root){

        if(!root) return;

        mp[root->val]++;
        solve(mp,root->left);
        solve(mp,root->right);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>mp;
        solve(mp,root);
        int max_count=0;
        for(auto i:mp){
            max_count=max(i.second,max_count);
        }

        vector<int>result;
        for(auto i:mp){
            if(i.second==max_count){
                result.push_back(i.first);
            }
        }

        return result;
    }
};