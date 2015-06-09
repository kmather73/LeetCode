/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
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
    public TreeNode sortedListToBST(ListNode head) {
        if(head == null){
            return null;
        }
        else if(head.next == null){
            return new TreeNode(head.val);
        }
        
        ListNode p = head;
        ListNode q = head.next;
        
        while(q.next != null && q.next.next != null){
            p = p.next;
            q = q.next.next;
        }
        
        TreeNode root = new TreeNode(p.next.val);
        root.right = sortedListToBST(p.next.next);
        
        p.next = null;
        root.left = sortedListToBST(head);
        
        return root;
    }
}
