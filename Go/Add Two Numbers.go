/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    newHead := ListNode{}
    curr := &newHead
    
    val := 0
    for l1 != nil || l2 != nil || val > 0{
        if l1 != nil {
            val += l1.Val
            l1 = l1.Next
        }
        
        if l2 != nil {
            val += l2.Val
            l2 = l2.Next
        }
        
        curr.Next = &ListNode{}
        curr = curr.Next
        curr.Val = val%10
        val /= 10
    }
    
    return newHead.Next
}
