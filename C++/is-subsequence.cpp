class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        int n = s.size();
        
        for(int i = 0; j < n && i < t.size(); ++i)
        {
            if(t[i] == s[j]) ++j;
        }
        
        return n == j;
    }
};
