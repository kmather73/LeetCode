/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
    
        ListNode *sumHead = new ListNode(0);
        ListNode *p = sumHead;
        int carry = 0;
        
        
        while (l1 && l2) {
            ListNode *node = new ListNode(0);
            int temp = l1->val + l2->val + carry;
            node->val = temp % 10;
            carry = temp / 10;
            p->next = node;
            p = p->next;

            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            ListNode *node = new ListNode(0);
            int temp = l1->val + carry;
            node->val = temp % 10;
            carry = temp / 10;
            p->next = node;
            p = p->next;

            l1 = l1->next;
        }
        while (l2) {
            ListNode *node = new ListNode(0);
            int temp = l2->val + carry;
            node->val = temp % 10;
            carry = temp / 10;
            p->next = node;
            p = p->next;

            l2 = l2->next;
        }

        if (carry != 0) {
            ListNode *node = new ListNode(carry);
            p->next = node;
            p = p->next;
        }
        
        return sumHead->next;
    }
};
