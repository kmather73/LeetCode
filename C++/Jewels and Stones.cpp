class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> j;
        
        for(auto ch : J) j[ch] = 1;
        
        int count = 0;
        for(auto ch : S) count += j[ch];
        
        return count;
    }
};
