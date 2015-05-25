/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
 //Recursively
public class Solution {
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null){return head;}
        
        ListNode newHead = reverseList(head.next);
        
        head.next.next = head;
        head.next = null;
        
        return newHead;
    }
    //Iteratively.
    public ListNode reverseList(ListNode head) {
        ListNode previous = null;
        while (head != null) {
            ListNode temp = head.next;
            head.next = previous;
            previous = head;
            head = temp;
        }
        return previous;
    }
}
