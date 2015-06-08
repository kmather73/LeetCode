/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
       int lengthOfA = 0;
       int lengthOfB = 0;
       
       ListNode p = headA;
       ListNode q = headB;
       
       while(p != null){
           p = p.next;
           ++lengthOfA;
       }
       while(q != null){
           q = q.next;
           ++lengthOfB;
       }
       
       p = headA;
       q = headB;
       
       if(lengthOfA > lengthOfB){
           for(int i = 0; i < lengthOfA - lengthOfB; ++i){
               p = p.next;
           }
       }
       else{
           for(int i = 0; i < lengthOfB - lengthOfA; ++i){
               q = q.next;
           }
       }
       
       while(true){
           if(p == q){
               return p;
           }
           
           p = p.next;
           q = q.next;
       }
    }
}
