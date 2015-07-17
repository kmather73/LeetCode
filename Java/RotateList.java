/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null)
           return head;
    
       int length = findLength(head);
       k = k % length;
       
       if(k == 0)
           return head;
       k = length - k;
       
       ListNode ahead = head;
       ListNode behind = head; 
       
       while(--k > 0)
          ahead = ahead.next;
       
       ListNode newHead = ahead.next;
       ahead.next = null;
       ahead = newHead;
       
       while(ahead.next!= null)
            ahead = ahead.next;
       
       ahead.next = head;
       return newHead;
    }
    
    private int findLength(ListNode head){
        int length = 0;
        
        while(head != null){
            head = head.next;
            ++length;
        }
        return length;   
    }
}
