/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
 // Recursive code
public class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        ListNode newHead = head.next;
        ListNode tailList = head.next.next;
        
        tailList = swapPairs(tailList);
        
        newHead.next = head;
        head.next = tailList;
        
        return newHead;
    }
} 
//Iterative code
    public ListNode swapPairs(ListNode head){
        if(head == null || head.next == null){
            return head;
        }
        
        ListNode newHead = new ListNode(0);
        ListNode previous = newHead;
        
        ListNode swapWith;
        
        while(head != null && head.next != null){
            swapWith = head.next;
            head.next = head.next.next;
            swapWith.next = head;
            
            previous.next = swapWith;
            previous = head;
            
            head = head.next;
        }
        return newHead.next;
    }
