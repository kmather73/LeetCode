class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> doesMatch;
        
        for(auto word : words)
        {
            if(MatchPattern(word, pattern)) doesMatch.push_back(word);
        }
        
        return doesMatch;
    }
    
    bool MatchPattern(string &s, string& p)
    {
        if(s.size() != p.size()) return false;
        unordered_map<char, char> map;
        unordered_map<char, char> used;
        for(int i=0; i < s.size(); ++i)
        {
            if(map.count(p[i]) && map[p[i]] != s[i]) return false;
            if(used.count(s[i]) && used[s[i]] != p[i]) return false;
            
            map[p[i]] = s[i];
            used[s[i]] = p[i];
        }
        
        return true;
    }
};
