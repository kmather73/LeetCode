








// Works but takes to much time.
public class Solution {
    
    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }
    
    public int jump(int[] nums) {
        int size = nums.length;
        
        int[] numberOfJumps = new int[size];
        for(int i = 0; i < size - 1; ++i){
            numberOfJumps[i] = Integer.MAX_VALUE - 1;
        }
        
        ListNode KnowToReachEnd = new ListNode(size - 1);
        
        for(int i = size - 2; i >= 0; --i){
            if( KnowToReachEnd.val - i <= nums[i]){
                KnowToReachEnd = updateList(KnowToReachEnd, i);
                
                ListNode p = KnowToReachEnd;
                while(p != null && p.val - i <= nums[i]){
                    numberOfJumps[i] = Math.min( numberOfJumps[i] , numberOfJumps[p.val] + 1 );
                    p = p.next;
                }
            }
        }
        return numberOfJumps[0];
    }
    
    public ListNode updateList(ListNode oldList, int i){
        ListNode head = new ListNode(i);
        head.next = oldList;
        return head;
    }
}
