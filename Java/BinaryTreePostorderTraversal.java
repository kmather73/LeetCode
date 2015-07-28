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
    public List<Integer> postorderTraversal(TreeNode root) {
        ArrayList<Integer> postorder = new ArrayList<Integer>();
        
        if(root == null){
            return postorder;
        }
        
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode curr = null;
        TreeNode prev = null;
        
        stack.push(root);
        
        while(!stack.isEmpty()){
            curr = stack.peek();
            
            if(prev == null || prev.left == curr || prev.right == curr){//We try and process the left sub tree first if availble.  
                if(curr.left != null){// checks to see if there is a left node to process.
                    stack.push(curr.left);
                }
                else if(curr.right != null){//If the current node has no left child but does have a right child then we process the right child before the current node.
                    stack.push(curr.right);
                }
                else{//if the current node has no children then we process it. This node is infact a leaf of the tree.
                    postorder.add(curr.val);
                    stack.pop();
                }
                
            
            }
            else if(curr.left == prev){// Backtraking up the tree from a left node.
                 if(curr.right != null){//Check to see if there is a right subtree that should be processed first.
                     stack.push(curr.right);
                 }
                 else{
                     postorder.add(curr.val);
                     stack.pop();
                 }
            }
            else{//Backtracking up the tree from the right.
                 postorder.add(curr.val);
                 stack.pop();
            }
            prev = curr;//updates what the last node visited was.
        }
        return postorder;
    }
}
