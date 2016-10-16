class Solution {
public:
    int longestPalindrome(string s) {
        bool one = false;
        unordered_map<char, int> count;
        for(char& ch: s) ++count[ch];
        
        int size=0;
        for(auto& p: count){
            one |= (p.second%2 == 1);
            size += 2*(p.second/2);
        }
        return size+one;
    }
};
