class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> counts;
        
        for(char ch: ransomNote) ++counts[ch];
        
        for(char ch: magazine){
            if(counts.find(ch) != counts.end()) --counts[ch];
        }
        
        bool canMake = true;
        for(auto kv: counts){
            canMake &= kv.second<=0;
        }
        
        return canMake;
    }
};
