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
    public boolean isValidBST(TreeNode root) {
        return isValid(root,Long.MIN_VALUE,Long.MAX_VALUE);
    }

    public boolean isValid(TreeNode root, long lower,long higher){

        if(root==null) return true;

        if(root.val<=lower || root.val>=higher) return false;

        if(!(isValid(root.left,lower,root.val)) || !(isValid(root.right,root.val,higher))) return false;

        return true; 
    }
}