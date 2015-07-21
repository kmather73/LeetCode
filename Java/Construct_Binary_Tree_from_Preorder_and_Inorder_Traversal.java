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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        
        //Checks to see if the input is valid.
        if(preorder == null || inorder == null){
            return null;
        }
        
        //Stores the index of a given node in the inorder traversal.
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        for(int i = 0; i < inorder.length; i++){
            map.put(inorder[i],i);
        }
        return buildTree(preorder, inorder, 0, preorder.length -1, 0, inorder.length -1, map);
    }
    
    public TreeNode buildTree(int[] preorder, int[] inorder, int preStart, int preEnd, int inorStart, int inorEnd, Map<Integer,Integer> map){
        
        if(preEnd < preStart || inorEnd < inorStart ){// To process null leafs.
            return null;
        }
        else if(preEnd == preStart){// Only enter the "if" statment if we are processing a leaf that is not null.
            TreeNode leaf = new TreeNode(preorder[preStart]);
            return leaf;
        }
        else{
            int center = preorder[preStart];// Pulls the value of the current center from the preoder.
            int index = map.get(center);//Find the index of where the current center is in the inorder.
            
            TreeNode parent = new TreeNode(center);
            
            parent.left = buildTree(preorder, inorder, preStart + 1, preStart + index - inorStart, inorStart, index -1, map);
            parent.right = buildTree(preorder, inorder, preStart + 1 + index - inorStart , preEnd, index + 1, inorEnd, map);
            
            return parent;
        }
        
    }
}
