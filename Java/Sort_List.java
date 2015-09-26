/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode sortList(ListNode head) {
        if(head == null || head.next == null)
            return head;
        
        ListNode p1 = head;
        ListNode p2 = head.next.next;
        
        while(p2 != null && p2.next != null) {
            p1 = p1.next;
            p2 = p2.next.next;
        }
        
        p2 = p1.next;
        p1.next = null;
        
        p1 = sortList(head);
        p2 = sortList(p2);
        
        return mergeList(p1, p2);
    }
    
    ListNode mergeList(ListNode p1, ListNode p2) {
        ListNode fakeHead = new ListNode(0);
        ListNode merged = fakeHead;
        
        while(p1 != null && p2 != null){
            if(p1.val < p2.val){
                merged.next = p1;
                p1 = p1.next;
            }
            else{
                merged.next = p2;
                p2 = p2.next;
            }
            merged = merged.next;
        }
        
        if(p1 != null)
            merged.next = p1;
        else
            merged.next = p2;
            
        return fakeHead.next;
    }
}
