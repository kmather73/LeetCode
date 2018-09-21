class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> set;
        for(auto s : A)
        {
            set.insert(hash(s));
        }
        
        return set.size();
    }
    
    string hash(string& s)
    {
        auto h = vector<vector<int>>(2, vector<int>(26));
        for(int i=0; i<s.size(); ++i)
        {
            auto ch = s[i];
            ++h[i%2][ch -'a'];
        }
        
        string even = "";
        string odd = "";
        
        for(int i=0; i<26; ++i)
        {
            even += h[0][i];
            odd += h[1][i];
        }
        
        return even + odd;
    }
};
