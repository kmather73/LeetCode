/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

public class BSTIterator {
    Stack<TreeNode> vals = new Stack<TreeNode>();
    TreeNode curr;
    
    public BSTIterator(TreeNode root) {
        curr = root;
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return vals.size() != 0 || curr != null;
    }

    /** @return the next smallest number */
    public int next() {
        while(curr != null){
            vals.push(curr);
            curr = curr.left;
        }
        
        TreeNode ans = vals.pop();
        curr = ans.right;
        
        return ans.val;
    }
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = new BSTIterator(root);
 * while (i.hasNext()) v[f()] = i.next();
 */
