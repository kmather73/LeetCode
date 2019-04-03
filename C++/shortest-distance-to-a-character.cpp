class Solution {
public:
    vector<int> shortestToChar(string &S, char C) {
        set<int> foundAt;
        
        for(int i=0; i < S.size(); ++i)
        {
            if(S[i] == C) 
            {
                foundAt.insert(i);
                foundAt.insert(-i);
            }
        }
        
        vector<int> v(S.size());
        for(int i=0; i < S.size(); ++i)
        {
            auto rightIt = foundAt.lower_bound(i);
            auto leftIt = foundAt.lower_bound(-i);
            
            auto right = rightIt != foundAt.end() ? *rightIt : 2*S.size();
            auto left = leftIt != foundAt.end() ? -(*leftIt) : -S.size();
            
            v[i] = min(i - left, right - i);
        }
        
        return v;
    }
};
