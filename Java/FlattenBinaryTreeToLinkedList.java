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
    public void flatten(TreeNode root) {
        if(root == null)
            return; 
        flattenUtill(root);
    }
    
    public TreeNode flattenUtill(TreeNode root){
        if(root.left == null && root.right == null)
            return root;
        
        TreeNode right = root.right;
        if(root.left != null){
            TreeNode node = flattenUtill(root.left);
            node.right = right;
            
            root.right = root.left;
            root.left = null;
            right = node;
        }
        if(right != null)
            right = flattenUtill(root.right);

        return right;
    }
}
