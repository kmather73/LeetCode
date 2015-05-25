/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
 
 /*Since this is java we pass the reference by copy and hence we can't use a funtion to 
 *handle the appending to the new list. */
public class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
      ListNode fakeHead = new ListNode(0);
      ListNode pointer = fakeHead;
      
      while(list1 != null && list2 != null){
          if(list1.val < list2.val){
              pointer.next = list1;
              list1 = list1.next;
              pointer = pointer.next;
          }
          else{
              pointer.next = list2;
              list2 = list2.next;
              pointer = pointer.next;
          }
      }
      
      if(list1 != null){
          pointer.next = list1;
      }
      else{
          pointer.next = list2;
      }
      return fakeHead.next;
    }
}
