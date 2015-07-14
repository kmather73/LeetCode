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
        if(p.val == q.val){
            return p;
        }
        else if(p.val > q.val ){
            return lowestCommonAncestor(root, q, p);
        }
        else if(p.val <= root.val && root.val <= q.val){
            return root;
        }
        else if(p.val < root.val ){
            return lowestCommonAncestor(root.left, p, q);
        }
        else
            return lowestCommonAncestor(root.right, p, q);
    }
}
