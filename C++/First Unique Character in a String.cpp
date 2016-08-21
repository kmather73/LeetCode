class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> counts;
        for(char ch: s) ++counts[ch];
        
        for(int i=0; i < s.size(); ++i) {
            if (counts[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};
