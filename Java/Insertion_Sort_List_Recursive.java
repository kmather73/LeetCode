/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode insertionSortList(ListNode head) {
        if(head == null)
            return head;
            
        ListNode min = removeMin(head);
        
        if(head != min) {
            min.next = head;
            head = min;
        }
        
        head.next = insertionSortList(head.next);
        return head;
    }
    
    public ListNode removeMin(ListNode head){
        ListNode min = head;
        ListNode prev = head;
        
        while(head.next != null){
            if(head.next.val < min.val){    
                prev = head;
                min = head.next;
            }
            head = head.next;
        }
        prev.next = min.next;
        return min;
    }
}
