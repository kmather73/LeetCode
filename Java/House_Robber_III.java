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
    
    public int rob(TreeNode root) {
        HashMap<TreeNode, Integer> values = new HashMap<TreeNode, Integer>();
        return rob(root, values);
    }
    
    public int rob(TreeNode root, HashMap<TreeNode, Integer> values){
        if(root == null)
            return 0;
        else if(values.containsKey(root))
            return values.get(root);
            
        //Rob root house.
        int money = root.val;
        if(root.left != null)
            money += rob(root.left.left, values) + rob(root.left.right, values);
        if(root.right != null)
            money += rob(root.right.left, values) + rob(root.right.right, values);
            
        //Don't rob root house.
        int moreMoney = rob(root.left, values)+rob(root.right, values);
        
        //Take Max money
        money = Math.max(money,moreMoney);
        values.put(root,money);
        
        return money;
    }
}
