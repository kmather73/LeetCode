class Solution {
public:
    bool validPalindrome(string &s) {
        int i = 0, j = s.size()-1;
        
        if(IsPalindrome(s, i, j)) return true;
        
        auto p = i+1;
        auto q = j-1;
            
        return IsPalindrome(s, p, j) || IsPalindrome(s, i, q);
    }
    
    inline bool IsPalindrome(string &s, int &i, int &j)
    {
        while(i < j && s[i] == s[j]) ++i, --j;
        
        return i >= j;
    }
};
