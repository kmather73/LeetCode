class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(auto s : stones)
        {
            q.push(s);
        }
        
        while(q.size() > 1)
        {
            auto y = q.top(); q.pop();
            auto x = q.top(); q.pop();
            auto diff = y - x;
            if(diff) q.push(diff);
        }
        
        return q.size() ?  q.top() : 0;
    }
};
