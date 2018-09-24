class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* p = head;
        ListNode* q = head;
        
        while(q && q->next)
        {
            q = q->next->next;
            p = p->next;
        }

        return p;
    }
};
