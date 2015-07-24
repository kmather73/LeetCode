//No extra memory;
public class Solution {
    public void reorderList(ListNode head) {
        if(head == null || head.next == null){
            return;
        }
        
        ListNode p = head;
        ListNode q = head;
        
        while(p.next != null && p.next.next != null){
            p = p.next.next;
            q = q.next;
        }
        
        p = q.next;
        q.next = null;
        
        p = reverseList(p);
        
        while(p != null && head != null){
            q = head.next;
            ListNode r = p.next;
            head.next = p;
            p.next = q;
            
            head = q;
            p = r;
        }
    }
    
    ListNode reverseList(ListNode head){
        if(head.next == null)
            return head;
        
        ListNode newHead = reverseList(head.next);
        head.next.next = head;
        head.next = null;
    
        return newHead;
    }
}




//This one uses O(n) extra memory.
public class Solution {
    public void reorderList(ListNode head) {
        if(head == null || head.next == null){
            return;
        }
        HashMap<Integer,ListNode> map = new HashMap<Integer,ListNode>();
        
        int count = 0;
        while(head != null){
            map.put(count++, head);
            head = head.next;
        }
        
        int right = --count;
        int left = 0;
        ListNode leftSide = null;
        ListNode rightSide = null;
    
        while(left + 1 < right){
            leftSide = map.get(left++);
            rightSide = map.get(right--);
            rightSide.next = leftSide.next;
            leftSide.next = rightSide;
        }
        map.get(right).next = null;
    }
}
