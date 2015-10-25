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
    public List<String> binaryTreePaths(TreeNode root) {
        ArrayList<String> paths = new ArrayList<String>();
        if(root == null)
            return paths;
        else if(root.left == null && root.right == null){
            String str = "" + root.val;
            paths.add(str);
        }
        
        if(root.left != null){
            List<String> leftPaths = binaryTreePaths(root.left);
            
            for(String str : leftPaths){
                paths.add(root.val +"->" + str);
            }
        }
        
        if(root.right != null){
            List<String> rightPaths = binaryTreePaths(root.right);
            
            for(String str : rightPaths){
                paths.add(root.val +"->" + str);
            }
        }
        
        return paths;
    }
}
