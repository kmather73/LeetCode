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
    public boolean isSymmetric(TreeNode root) {
        if(root == null){
            return true;
        }
        else{
            return mirrorOf(root.left, root.right);
        }
    }
    
    //A function that will return true of one tree is the mirror of the other and false otherwise.
    public boolean mirrorOf(TreeNode root1, TreeNode root2){
        if(root1 == null && root2 == null){
            return true;
        }
        else if(root1 == null || root2 == null || root1.val != root2.val){
            return false;
        }
        else{
            return mirrorOf(root1.left, root2.right) && mirrorOf(root1.right, root2.left);
        }
    }
}
