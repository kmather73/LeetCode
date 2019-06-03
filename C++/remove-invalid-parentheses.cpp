class Solution {
unordered_map<char, int> costs {{'(', 1}, {')', -1}};
    
    public:
    vector<string> removeInvalidParentheses(string &s) {
        set<string> bag;
        string pad = "";
        int maxsize = 0;
        BackTracking(s, 0, s.size(), bag, 0, pad, maxsize);
        
        vector<string> list;
        for(auto s : bag) list.push_back(s);
        
        return list;
    }
    
    void BackTracking(string &s, int i, int n, set<string> &valid, int cost, string& pad, int &maxSize)
    {
        if(i == n || cost < 0)
        {
            if(cost == 0)
            {
                if(maxSize < pad.size())
                {
                    valid.clear();
                    maxSize = pad.size();
                }
                
                if(maxSize == pad.size()) valid.insert(pad);
            }
            
            return;
        }
        
        auto charge = costs.count(s[i]) ? costs[s[i]] : 0;
        pad.push_back(s[i]);
        BackTracking(s, i+1, n, valid, cost+charge, pad, maxSize);
        pad.pop_back();
            
        if(charge) BackTracking(s, i+1, n, valid, cost, pad, maxSize);
    }
};
