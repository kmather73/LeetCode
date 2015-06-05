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
    public int countNodes(TreeNode root) {
        if(root == null){
            return 0;
        }
        
        int leftHeight = leftHeight(root);
        int rightsLeftHeight = leftHeight(root.right);
        
        if(leftHeight == rightsLeftHeight + 1){
            return (1 << rightsLeftHeight ) + countNodes(root.right);
        }
        else{
            return (1 << rightsLeftHeight )  + countNodes(root.left);
        }
    }
    
    public int leftHeight(TreeNode root){
        int height = 0;
        
        while(root != null){
            ++height;
            root = root.left;
        }
        return height;
    }
}
