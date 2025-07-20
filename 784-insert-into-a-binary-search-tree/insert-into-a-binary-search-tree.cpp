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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        pair<TreeNode* , bool>p =solve(root,val);
        TreeNode* parent = p.first;
        TreeNode* child = new TreeNode(val);
        if(p.second){
            parent->left=child;
        }else parent->right = child;

        return root;
    }
    pair<TreeNode*,bool>solve(TreeNode* root,int val){
        if(!root) return {};

        if(root->val>val && root->left==nullptr) return {root,true};

        if(root->val<val&& root->right==nullptr) return {root,false};

        if(root->val<val) return solve(root->right,val);
        else return solve(root->left,val);
    }
};