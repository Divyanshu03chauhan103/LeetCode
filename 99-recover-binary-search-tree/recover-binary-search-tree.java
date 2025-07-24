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
class Solution {
    TreeNode prev, first, last, middle;
    public void recoverTree(TreeNode root) {
        prev=new TreeNode(Integer.MIN_VALUE);

        first=last=middle=null;
        inorder(root);
       
        if(first!=null && last!=null){
            int t=first.val;
            first.val=last.val;
            last.val=t;
        }else if(first!=null){
           
            int t=first.val;
            first.val=middle.val;
            middle.val=t;
        }
    }

    public void inorder(TreeNode root){
        if(root==null) return;

        inorder(root.left);
        if(first==null && prev.val>root.val){
            first=prev;
            middle=root;
        }else if(last==null && prev.val >root.val) last=root;
        prev=root;
        inorder(root.right);
    }
}