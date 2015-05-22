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
    public ListNode partition(ListNode head, int x) {
        if(head == null || head.next == null){
            return head;
        }
        
        ListNode lessThan = new ListNode(0);//Fake head to all the elements lessthan x.
        ListNode greaterThan = new ListNode(0);//Fake head to all the elements greater than or equalt to x.
        
        ListNode p1 = lessThan;//pointers to the current element in the less than list.
        ListNode p2 = greaterThan;// pointer to the currentelement in the greater than list.

        while(head != null){
            if(head.val < x){//add element to the lessthan list.
                p1.next = head;
                p1 = p1.next;
            }
            else{//add element to the greaterthan list.
                p2.next = head;
                p2 = p2.next;
            }
            head = head.next;//Move on to the next element.
        }
        p2.next = null;// Makes sure this is no loop in the linkedlist.
        p1.next = greaterThan.next;//Make the lessthan element list join up with the greaterthan list.
        return lessThan.next;//return the partitioned list.
    }
}
