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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> LevelOrder = new ArrayList<List<Integer>>();
        
        levelHelper(LevelOrder, root, 0);
        
        return LevelOrder;
    }

    public void levelHelper(List<List<Integer>> levelOrder, TreeNode root, int height) {
        if (root == null){
            return;
        }
        
        if (height >= levelOrder.size()) {
            levelOrder.add(new LinkedList<Integer>());
        }
        
        levelOrder.get(height).add(root.val);
        levelHelper(levelOrder, root.left, height + 1);
        levelHelper(levelOrder, root.right, height + 1);
    }
}
