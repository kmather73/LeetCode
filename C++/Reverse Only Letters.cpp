class Solution {
public:
    string reverseOnlyLetters(string S) {
        int p = 0;
        int q = S.size()-1;
        
        while(p < q)
        {
            while(NotALetter(S[p]) && p < q) ++p;
            
            while(NotALetter(S[q]) && p < q) --q;
            
            if(p < q) swap(S[p++], S[q--]);
        }
        
        return S;
    }
    
    bool NotALetter(char ch)
    {
        return !isalpha(ch);
    }
};
