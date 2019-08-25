class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> fWords;
        for(auto &word : words)
        {
            fWords.push_back(f(word));
        }
        
        sort(fWords.begin(), fWords.end());
        
        vector<int> smaller;
        for(auto &q : queries)
        {
            auto fq = f(q);
            auto it = upper_bound(fWords.begin(), fWords.end(), fq);
            
            smaller.push_back(fWords.end() - it);
        }
        
        return smaller;
        
    }
    
    int f(const string &str)
    {
        vector<int> v(26);
        for(auto ch : str) ++v[ch - 'a'];
        
        for(int i=0; i < 26; ++i)
        {
            if(v[i]) return v[i];
        }
        
        return 0;
    }
};
