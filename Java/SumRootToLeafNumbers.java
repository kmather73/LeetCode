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
    public int sumNumbers(TreeNode root) {
        if(root == null)
            return 0;
        return sumNumbersUtill(root,root.val);
    }
    
    public int sumNumbersUtill(TreeNode root, int sum){
        if(root.left == null && root.right == null)
            return sum;
        int left = 0;
        int right = 0;
        
        if(root.left != null)
            left = sumNumbersUtill(root.left,sum*10 + root.left.val);
        if(root.right != null)
            right = sumNumbersUtill(root.right,sum*10 + root.right.val);
        return  right + left; 
    }
}
