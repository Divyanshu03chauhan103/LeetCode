class Solution {
public:
    int solve(TreeNode* root, int minVal){
        if(!root) return -1;
        
        if(root->val > minVal) return root->val;
        
        int left = solve(root->left, minVal);
        int right = solve(root->right, minVal);

        if(left == -1) return right;
        if(right == -1) return left;
        return min(left, right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        
        int secondMin = solve(root, root->val);
        
        return secondMin;
    }
};
