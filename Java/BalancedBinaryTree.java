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
    public static final Set<Integer> heights = new HashSet<Integer>() {{
    add(-1);
    add(0);
    add(1);
}};
    public boolean isBalanced(TreeNode root) {
        int balanced = isBlanacedUtill(root);
        return balanced < 0 ? false : true;
    }
    
    public int isBlanacedUtill(TreeNode root){
        if(root == null)
            return 0;
            
        int leftHeight = isBlanacedUtill(root.left);
        int rightHeight = isBlanacedUtill(root.right);
            
        if(leftHeight < 0 || rightHeight < 0 || !heights.contains(leftHeight - rightHeight))
            return -1;
        else
            return 1 + Math.max(leftHeight,rightHeight);
    }
}
