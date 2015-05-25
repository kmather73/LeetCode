/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeElements(ListNode head, int val) {
       if(head == null){
           return null;
       }
       
       ListNode start = head;
       while(start != null && start.val == val){//Remove the prefix of values from the list if it exists.
           start = start.next;
       }
       
       ListNode pointer = start;
       ListNode temp = null;
       
       while(pointer != null && pointer.next != null){
           if(pointer.next.val == val){
               temp = pointer.next;
               while(temp != null && temp.val == val){//Find the next values that is valid.
                   temp = temp.next;
               }
               pointer.next = temp;
           }
           pointer = pointer.next;
       }
       return start;
    }
}
