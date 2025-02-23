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
    TreeNode* solve(vector<int>& preorder,vector<int>&postorder,int prestart,int poststart,int prend,unordered_map<int,int>&mp){

        if(prestart>prend) return NULL;

        TreeNode* root = new TreeNode(preorder[prestart]);

        if(prestart==prend) return root;

        int nextNode = preorder[prestart+1];

        int j = mp[nextNode];
        int num = j-poststart+1;

        root->left = solve(preorder,postorder,prestart+1,poststart,prestart+num,mp);
        root->right = solve(preorder,postorder,prestart+num+1,j+1,prend,mp);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        int n= postorder.size()-1;
        for(int i=0;i<=n;i++){
            mp[postorder[i]]=i;
        }
        return solve(preorder,postorder,0,0,n,mp);
    }
};