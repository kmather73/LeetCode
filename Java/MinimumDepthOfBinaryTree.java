/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int minDepth(TreeNode root) {
        if(root == null)
            return 0;
        return minDepthUtill(root);
    }
    
    public int minDepthUtill(TreeNode root){
        if(root.left == null && root.right == null)
            return 1;
        else{
            int left = Integer.MAX_VALUE;
            int right = Integer.MAX_VALUE;
            if(root.left != null)
                left = minDepthUtill(root.left);
            if(root.right!= null)
                right = minDepthUtill(root.right);
            return 1 + Math.min(left, right);
        }
    }
}
