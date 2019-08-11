using DP = unordered_map<string, int>;
using MAP = unordered_map<int, vector<reference_wrapper<string>>>;
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        MAP mp;
        for(auto &word : words) mp[word.size()].push_back(word);
        
        DP dp;
        int m = 0;
        for(auto &word : words)
        {
            m = max(m, FindLongestPath(dp, mp, word));
        }
        
        return m;
    }
    
    int FindLongestPath(DP &dp, MAP& mp, string& str)
    {
        if(dp.count(str)) return dp[str];
        
        int m = 0;
        for(auto str2 : mp[str.size() + 1])
        {
            if(IsPredecessor(str, str2))
            {
                m = max(m, FindLongestPath(dp, mp, str2));
            }
        }
        
        return dp[str] = 1 + m;
    }
    
    bool IsPredecessor(string s, string t)
    {
        int i = 0, j = 0;
        while(i < s.size() && i+1 >= j)
        {
            while(i < s.size() && s[i] == t[j]) ++i, ++j;
            
            if(i < s.size() && s[i] != t[j]) ++j;
        }
        
        return i+1 == t.size();
    }
};
