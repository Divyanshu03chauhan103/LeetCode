/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class pair{
    TreeNode parent;
    boolean side;
    pair(){}
    pair(TreeNode parent,boolean side){
        this.parent = parent;
        this.side=side;
    }
    
}
class Solution {
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if(root==null) return new TreeNode(val);
        boolean isLeft = false;
        pair p=solve(root,val);
    
        TreeNode parent = p.parent;
        isLeft=p.side;
        TreeNode child = new TreeNode(val);
        if(isLeft){
           parent.left=child;

        }else parent.right = child;

        return root;
    }

    public pair solve(TreeNode root,int val ){
        if(root==null) return null;

        if(root.val<val && root.right==null) return new pair(root,false);
        if(root.val>val && root.left==null) return new pair(root,true);

        pair right=new pair();
        pair left=new pair();
        if(root.val<val){
            right=solve(root.right,val);
        }
        else left=solve(root.left,val);

        return left.parent==null?right:left;
    }
}