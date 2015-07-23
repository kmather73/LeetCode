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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1)
            return head;
        
        ListNode* p = head;
        for(int i = 0; i < k-1 && p; ++i)
            p = p->next;   
        if(!p)
            return head;
        
        ListNode* next = p->next;
        p->next = NULL;
        ListNode* newHead = reverseList(head);
        head->next = reverseKGroup(next,k);
        return newHead;
    }
    
    ListNode* reverseList(ListNode* head){
        if(head->next == NULL)
            return head;
        
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return newHead;
    }
};
