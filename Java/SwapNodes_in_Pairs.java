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
        
        ListNode newHead = head.next;
        ListNode swapWith = head.next;
        ListNode tempData;
        
        while(swapWith.next != null){
            temp = swapWith.next;
            swapWith.next = head;
            head.next = temp;
            
            head = head.next;
            swapWith = head.next;
        }
        
        return newHead;
    }
