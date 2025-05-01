class Solution {
public:
    bool checkTree(TreeNode* root) {
        if (!root || !root->left || !root->right)
            return false;
        
        return root->val == root->left->val + root->right->val;
    }
};
