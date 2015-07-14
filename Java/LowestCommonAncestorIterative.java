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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(p.val > q.val){
            TreeNode temp = p;
            p = q;
            q = temp;
        }
        
        while(true){
            if(root.val == p.val || root.val == q.val)
                return root;
            else if(p.val < root.val && root.val < q.val)
                return root;
            else if(p.val < root.val)
                root = root.left;
            else
                root = root.right;
        }
    }
}
