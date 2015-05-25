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
    public ListNode addTwoNumbers(ListNode list1, ListNode list2) {
       ListNode fakeHead = new ListNode(0);
       ListNode curr = fakeHead;
       
       int carry = 0;
       while(list1 != null || list2 != null){
           int value = 0;
           if (list1 != null){
               value += list1.val;
               list1 = list1.next;
           }
           if(list2 != null){
               value += list2.val;
               list2 = list2.next;
           }
           value += carry;
           carry = value / 10;
           
           ListNode next = new ListNode(value % 10);
           curr.next = next;
           curr = next;
       }
       
       if(carry == 1 ){
           ListNode lastOne = new ListNode(1);
           curr.next = lastOne;
       }
       return fakeHead.next;
    }
}
