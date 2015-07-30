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
    public List<Integer> preorderTraversal(TreeNode root) {
        ArrayList<Integer> preorder = new ArrayList<Integer>();
        
        if(root == null){
            return preorder;
        }
        
        Stack<TreeNode> stack = new Stack<TreeNode>();
        stack.push(root);
        
        TreeNode curr = null;
        TreeNode prev = null;
        
        while(!stack.isEmpty()){
            curr = stack.pop();
            
            if(prev == null || prev.left == curr || prev.right == curr){
                preorder.add(curr.val);
                
                if(curr.right != null){
                    stack.push(curr.right);
                }
                if(curr.left != null){
                    stack.push(curr.left);
                }
            }
            else{
                preorder.add(curr.val);
                
                if(curr.right != null){
                    stack.push(curr.right);
                }
                if(curr.left != null){
                    stack.push(curr.left);
                }
            }
            prev = curr;
            
        }
        return preorder;
    }
}
