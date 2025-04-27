/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int solve(Node* root){

        if(!root) return 0;
        int ans=0;
        for(auto i:root->children){
            ans=max(solve(i),ans);
        }
        return ans+1;
    }
    int maxDepth(Node* root) {
        
        int depth=0;
        return solve(root);

       
    }
};