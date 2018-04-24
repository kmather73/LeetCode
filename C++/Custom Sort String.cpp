class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char, int> order;
        for(int i=0; i < S.size(); ++i)
        {
            order[S[i]] = i;
        }
        
        for(auto ch : T)
        {
            if(!order.count(ch))
            {
                order[ch] = -1;
            }
        }
        
        sort(T.begin(), T.end(), [&](const char a, const char b){return order[a] < order[b];});
        
        return T;
    }
};
