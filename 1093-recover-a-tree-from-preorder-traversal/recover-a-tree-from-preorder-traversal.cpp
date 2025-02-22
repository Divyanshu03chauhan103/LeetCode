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

    TreeNode* solve(int &depth,int &i,string &s){

        if(i>=s.length())
            return NULL;

        int j=i;
        while(j<s.length() && s[j]=='-'){
            j++;
        }

        int dash = j-i;
        if(depth!= dash)
            return NULL;
        
        i=j;

        int num=0;
        while(i<s.length() && isdigit(s[i])){
            num = num*10 + (s[i]-'0');
            i++;
        }

        TreeNode* currNode= new TreeNode(num);
        depth++;
        currNode->left = solve(depth,i,s);
        currNode->right=solve(depth,i,s);
        depth--;
        return currNode;
        }
    TreeNode* recoverFromPreorder(string traversal) {
        
        int depth=0;
        int i=0;
        return solve(depth,i,traversal);
    }
};