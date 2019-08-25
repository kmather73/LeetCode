class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> sums;
        ListNode fakeHead(0);
        ListNode* p = &fakeHead;
        p->next = head;
        
        int sum = 0;
        while(p)
        {
            sum += p->val;
            if(sums.count(sum))
            {
                p = sums[sum]->next;
                auto currSum = sum + p->val;
                while(sum != currSum)
                {
                    sums.erase(currSum);
                    p = p->next;
                    currSum += p->val;
                }
                
                sums[sum]->next = p->next;
            }
            else
            {
                sums[sum] = p;
            }
            
            p = p->next;
        }
        
        return fakeHead.next;
    }
};
