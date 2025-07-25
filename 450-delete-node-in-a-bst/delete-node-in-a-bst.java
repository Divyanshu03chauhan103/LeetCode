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
    public TreeNode deleteNode(TreeNode root, int key) {
        
        if(root==null) return root;
        
        if(root.val==key){
            return helper(root);
        }
        TreeNode dummy=root;

        while(root!=null){
            if(root.val<key){
                if(root.right!=null && root.right.val==key){
                    root.right=helper(root.right);
                    break;
                }else{
                    root=root.right;
                }
            }else{

                if(root.left!=null && root.left.val==key){
                    root.left=helper(root.left);
                    break;
                }
                else root=root.left;
            }
        }

        return dummy;
    }

    public TreeNode helper(TreeNode root){
        if(root.left==null) return root.right;
        if(root.right==null) return root.left;

        TreeNode rightChild=root.right;
        TreeNode leftRightChild = findRight(root.left);
        
        leftRightChild.right=rightChild;
        return root.left;
    }

    public TreeNode findRight(TreeNode root){
        if(root.right==null) return root;
        return findRight(root.right); 
    }
}