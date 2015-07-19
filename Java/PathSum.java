public class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root == null)
            return false;
        else if(root.left == null && root.right == null)
            return sum == root.val;
        else
            return hasPathSum(root.left, sum - root.val) || hasPathSum(root.right, sum - root.val);
    }
}
