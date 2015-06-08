/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if(m == n){
            return head;
        }
        
        ListNode fakeHead = new ListNode(0);
        fakeHead.next = head;
        ListNode p1 = fakeHead;
        
        for(int i = 0; i < m - 1; ++i){//advance pointer to the element preceding the m-th element.
            p1 = p1.next;
        }
        
        ListNode p2 = p1.next;
        ListNode q = null;
        
        for(int i = m; i < n; ++i){
            ListNode temp = p2.next;
            p2.next = q;
            q = p2;
            p2 = temp;
        }
        
        p1.next.next = p2.next;
        p2.next = q;
        p1.next = p2;
        
        return fakeHead.next;
    }
}
