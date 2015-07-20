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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> myLists = new ArrayList<List<Integer>>();
        List<Integer> myList = new ArrayList<Integer>();
        
        pathSumUtill(myLists, myList, root, sum);
        return myLists;
    }
    
    public void pathSumUtill(List<List<Integer>> myLists, List<Integer> myList,TreeNode root, int sum) {
        if(root == null)
            return;
        
        myList.add(root.val);
        if(root.left == null && root.right == null && sum == root.val)
            myLists.add(new ArrayList<Integer>(myList) );
        else {
            pathSumUtill(myLists, myList, root.left, sum - root.val);
            pathSumUtill(myLists, myList, root.right, sum - root.val);
        }
        myList.remove(myList.size() - 1);
        
    }
}
