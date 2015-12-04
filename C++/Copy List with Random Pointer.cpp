/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return head;
            
        RandomListNode* p = head;
        RandomListNode* q;
        
        while(p != NULL){
            q = new RandomListNode( p->label );
            q->next = p->next;
            p->next = q;
            p = q->next;
        }
        
        p = head;
        while(p != NULL){
            q = p->next;
            if(p->random != NULL)
                q->random = p->random->next;
            p = q->next;
        }
        
        
        p = head;
        head = head->next;
        
        while(p != NULL){
            q = p->next;
            p->next = q->next;
            p = p->next;
            if (q->next != NULL) q->next = q->next->next;
        }
        
        return head;
    }
};
