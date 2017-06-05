class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;
        for(const auto& ch: t) ++mp[ch];
        
        
        for(const auto& ch: s) --mp[ch];
        
        
        for(const auto &x: mp){
            if( x.second > 0) return x.first;
        }
        
        return ' ';
    }
};
