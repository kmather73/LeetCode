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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> myLists = new ArrayList<List<Integer>>();

        Stack<TreeNode> leftToRight = new Stack<TreeNode>();
        Stack<TreeNode> rightToLeft = new Stack<TreeNode>();
        
        leftToRight.add(root);
        TreeNode temp = null;
        
        int leftSize = 1;
        int rightSize = 0;
        
        while(leftSize > 0 || rightSize > 0 ){
            List<Integer> level = new ArrayList<Integer>();
            
            while(leftSize-- > 0){
                temp = leftToRight.pop();
                if(temp == null)
                    continue;
                level.add(temp.val);
                rightToLeft.push(temp.left);
                rightToLeft.push(temp.right);
            }
            
            while(rightSize-- > 0 ){
                temp = rightToLeft.pop();
                
                if(temp == null)
                    continue;
                level.add(temp.val);
                leftToRight.push(temp.right);
                leftToRight.push(temp.left);
            }
            
            leftSize = leftToRight.size();
            rightSize = rightToLeft.size();
            myLists.add(level);
        }
        myLists.remove(myLists.size()-1);
        return myLists;
    }
}
