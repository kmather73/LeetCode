class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<pair<int,int>> stack;
        vector<int> larger;
        
        auto i = 0;
        auto h = head;
        while(h)
        {
            while(stack.size() && stack.back().first < h->val)
            {
                auto top = stack.back(); stack.pop_back();
                larger[top.second] = h->val;
            }
            
            stack.push_back(make_pair(h->val, i));
            h = h->next;
            larger.push_back(0);
            ++i;
        }
        
        return larger;
    }
};
