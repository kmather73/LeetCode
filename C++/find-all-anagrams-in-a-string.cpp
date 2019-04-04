class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> idx;
        
        unordered_map<char, int> gram, window;
        for(auto ch : p) ++gram[ch];
        
        int n = p.size();
        int m = s.size();
        
        for(int i=0; i < m; ++i)
        {
            if(i >= n) --window[s[i-n]];
            ++window[s[i]];
            if(SameGram(gram, window)) idx.push_back(i-n+1);
        }
        
        return idx;
    }
    
    inline bool SameGram(unordered_map<char, int> &a, unordered_map<char, int> &b)
    {
        for(auto x : a) if(b[x.first] != x.second) return false;
        for(auto x : b) if(a[x.first] != x.second) return false;
        return true;
    }
};
