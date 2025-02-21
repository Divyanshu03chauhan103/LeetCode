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
class FindElements {
public:
    unordered_set<int>s;
    // TreeNode* head;
    FindElements(TreeNode* root) {
        // head=root;
       dfs(root,0);

    }
    void dfs(TreeNode* root,int x){

        if(!root) return ;

        root->val =x;
        s.insert(x);
        dfs(root->left,2*x+1);
        dfs(root->right,2*x+2);
    }
    // bool solve(TreeNode* root, int target){

    //     if(!root) return false;
    //     if(root->val == target) return true;
        
    //     return solve(root->left,target)||
    //     solve(root->right,target);

    // }
    bool find(int target) {
        
        return s.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */