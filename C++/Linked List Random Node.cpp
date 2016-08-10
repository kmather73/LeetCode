class Solution {
private:
    ListNode* head;
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int length = 1; int reservoir;
        ListNode* temp = head;
        
        while(temp != nullptr){
            if ( rand()%length == 0 ) reservoir = temp->val;
            
            temp = temp->next;
            ++length;
        }
        
        return reservoir;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
