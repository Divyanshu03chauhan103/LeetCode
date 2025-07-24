class Solution {
    ArrayList<Integer> arr = new ArrayList<>();

    public void fillArray(TreeNode root) {
        if (root == null) return;

        // NORMAL inorder to get sorted values
        fillArray(root.left);
        arr.add(root.val);
        fillArray(root.right);
    }

    public void recoverTree(TreeNode root) {
        fillArray(root);
        Collections.sort(arr); 
        int[] i = new int[1];
        inorderCheck(root, i);
    }

    public void inorderCheck(TreeNode root, int[] i) {
        if (root == null) return;

        inorderCheck(root.left, i);
        root.val = arr.get(i[0]);
        i[0]++;
        inorderCheck(root.right, i);
    }
}
