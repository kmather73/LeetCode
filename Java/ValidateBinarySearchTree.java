/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public boolean isValidBST(TreeNode root) {
        if(root!= null){
            if(root.left == null && root.right== null){
                return true;
            }
        }
        return isValidBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
    
    public boolean isValidBST(TreeNode root, long min, long max){
        if(root == null){
            return true;
        }
        else if(root.val <= min || root.val >= max ){
             return false;
        }

        return isValidBST(root.left,min,root.val) && isValidBST(root.right,root.val,max);
    }
}
