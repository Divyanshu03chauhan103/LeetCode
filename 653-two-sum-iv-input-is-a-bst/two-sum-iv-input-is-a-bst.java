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
    public boolean findTarget(TreeNode root, int k) {
        
        HashSet<Integer>mp=new HashSet<>();

        return solve(mp,root,k);
    }

    public boolean solve(HashSet<Integer>mp,TreeNode root, int k){

        if(root==null) return false;

        if(mp.contains(k-root.val)) return true;

        mp.add(root.val);
        return solve(mp,root.left,k)||solve(mp,root.right,k);
    }
}