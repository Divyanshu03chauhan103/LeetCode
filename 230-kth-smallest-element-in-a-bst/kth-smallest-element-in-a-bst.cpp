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
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int>pq;
        
        dfs(pq,root);
        while(pq.size()!=k){
            pq.pop();
        }
        return pq.top();
    }
    void dfs(priority_queue<int>&pq,TreeNode* root){
        if(!root) return ;
        pq.push(root->val);
        dfs(pq,root->left);
       
        dfs(pq,root->right);
        
    }
};
