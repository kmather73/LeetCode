class Solution 
{
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) 
    {
        use_limit = min(use_limit, num_wanted);
        
        unordered_map<int, multiset<int>> queueTable;
        
        for (int i=0; i < values.size(); ++i)
        {
            queueTable[labels[i]].insert(values[i]);
            if(queueTable[labels[i]].size() > use_limit) queueTable[labels[i]].erase(queueTable[labels[i]].begin());
        }
        
        auto cmp = [](const multiset<int>& e1, const multiset<int>& e2) 
        { 
            return *e1.rbegin() < *e2.rbegin();
        };
        
        priority_queue<multiset<int>, vector<multiset<int>>, decltype(cmp)> HyperQueue(cmp);
        for(auto qpair : queueTable) HyperQueue.push(qpair.second);
        
        auto sum = 0;
        while (HyperQueue.size() && num_wanted)
        {
            --num_wanted;
            
            auto topQ = HyperQueue.top(); HyperQueue.pop();
            sum += *topQ.rbegin();
            topQ.erase(--topQ.end());
            
            if (topQ.size()) HyperQueue.push(topQ);
        }
        
        return sum;
    }
};
