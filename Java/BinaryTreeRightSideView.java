/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
 //One could also do a BFS and just keep track of when you transition from one level to the next, but thats kkinda boaring.
public class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> rightSide = new ArrayList<Integer>();
        
        if(root == null){
            return rightSide;
        }
        rightSide.add(root.val);
        
        List<Integer> leftsRightSide = rightSideView(root.left);// finds the left subTrees rightside view.
        List<Integer> rightsRightSide = rightSideView(root.right);// finds teh right subTrees rightside view.
        
        mergeLists(rightSide, leftsRightSide, rightsRightSide);//merges both rightside views of the roots subtrees.
        return rightSide;
    }
    
    //Merges the left and right lists with the center list. First we append all the right ellements. If there were R elements in the right     //list we would add all the elements in the left list after the first R many if any are left.
    public void mergeLists(List<Integer> center, List<Integer> left, List<Integer> right){
        Iterator<Integer> leftIterator = left.iterator();
        Iterator<Integer> rightIterator = right.iterator();
        
        while(rightIterator.hasNext()){
            center.add(rightIterator.next());
            
            if(leftIterator.hasNext()){
                leftIterator.next();
            }
        }
        
        while(leftIterator.hasNext()){
            center.add(leftIterator.next());
        }
    }
}
