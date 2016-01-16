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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head){
            ListNode* p = head;
            ListNode* q = p->next;
            ListNode* temp;
            
            while(q && q->next) {
                temp = p->next;
                p->next = q->next;
                p = p->next;
                
                q->next = p->next;
                p->next = temp;
                q = q->next;
            }
        }
        return head;
    }
};
