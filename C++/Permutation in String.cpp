class Solution {
public:
    bool checkInclusion(string &s1, string &s2) {
        if(s1.size() > s2.size()) return false;
        
        int n = s1.size();
        int hash = 0;
        unordered_map<char, int> mp;
        
        for(int i=0; i < n; ++i) addAndSubChar(s1[i], s2[i], hash, mp);
        
        if(hash == 0 && onlyZeros(mp)) return true;
        
        for(int i=n; i < s2.size(); ++i) {
            addAndSubChar(s2[i-n], s2[i], hash, mp);
            
            if(hash == 0 && onlyZeros(mp)) return true;
        }
        
        return false;
    }
    
    void addAndSubChar(char ch1, char ch2, int &hash, unordered_map<char, int> &mp){
        hash += ch1 - ch2;
        ++mp[ch1];
        --mp[ch2];
    }
    
    bool onlyZeros(unordered_map<char, int> &mp){
        bool allZeros = true;
        for(const auto &x : mp) {
            allZeros &= x.second == 0;
        }
            
        return allZeros;
    }
};
