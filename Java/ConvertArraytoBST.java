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
    public TreeNode sortedArrayToBST(int[] nums) {
        return arrayToBSTUtill(nums, 0 , nums.length - 1);
    }
    
    public TreeNode arrayToBSTUtill(int[] nums, int start, int end){
        if(start > end){
            return null;
        }
        else if(start == end){
            return new TreeNode(nums[start]);
        }

        int mid = (start + end) / 2;
        TreeNode root = new TreeNode(nums[mid]);
        
        root.left = arrayToBSTUtill(nums, start, mid -1);
        root.right = arrayToBSTUtill(nums, mid + 1, end);
        
        return root;
    }
}
