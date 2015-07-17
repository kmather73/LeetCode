/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
            
        ListNode ahead = head;
        ListNode behind = head;
        
        while(n-- > 0)
            ahead = ahead.next;
            
        if(ahead == null)
            return head.next;
            
        while(ahead.next != null){
            ahead = ahead.next;
            behind = behind.next;
        }
    
        behind.next = behind.next.next;
        return head;
    }
}
