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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if(inorder == null || postorder == null || inorder.length != postorder.length){
            return null;
        }
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        
        //Stores the nodes value with its index in the array.
        for(int i=0 ; i < inorder.length; ++i){
            map.put(inorder[i], i);
        }
        return buildTree(inorder, postorder, 0, inorder.length - 1, 0, postorder.length - 1, map);
    }
    
    public TreeNode buildTree(int[] inorder, int[] postorder, int inoStart, int inoEnd, int postStart, 
                                int postEnd, Map<Integer,Integer> map) {
        if(inoEnd < inoStart || postEnd < postStart || postEnd >= postorder.length || inoEnd >= inorder.length){ 
            return null;
        }
        if(inoEnd == inoStart){
            TreeNode leaf = new TreeNode(inorder[inoStart]);
            return leaf;
        }
        
        int center = postorder[postEnd];
        int index = map.get(center);
        
        TreeNode parent = new TreeNode(center);

        parent.left = buildTree(inorder, postorder, inoStart, index - 1, postStart, postStart + index - inoStart - 1, map);
        parent.right = buildTree(inorder, postorder, index + 1, inoEnd, postStart + index - inoStart, postEnd - 1, map); 
        
        return parent;
    }
}
