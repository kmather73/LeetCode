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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        LinkedList<List<Integer>> LevelOrder = new LinkedList<List<Integer>>();
        
        levelHelper(LevelOrder, root, 0);
        //Collections.reverse(LevelOrder);       
        return LevelOrder;
    }

    public void levelHelper(LinkedList<List<Integer>> levelOrder, TreeNode root, int height) {
        if (root == null){
            return;
        }
        
        if (height >= levelOrder.size()) {
            levelOrder.addFirst(new ArrayList<Integer>());
        }
        
        levelOrder.get(levelOrder.size() - 1 - height).add(root.val);
        levelHelper(levelOrder, root.left, height + 1);
        levelHelper(levelOrder, root.right, height + 1);
    }
}




// Does the level order in the normal way then reverses the list.
public class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> LevelOrder = new ArrayList<List<Integer>>();
        
        levelHelper(LevelOrder, root, 0);
        Collections.reverse(LevelOrder);       
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
