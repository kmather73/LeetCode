class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string str ="";
        int c=0;
        for(int i=S.size()-1; i >= 0; --i){
            if(c == K && S[i] != '-'){
                str = ((char)toupper(S[i])) + ('-' + str);
                c = 1;
            } else if(S[i] != '-'){
                ++c;
                str = ((char)toupper(S[i])) + str;
            } 
        }
        
        return str;
    }
};
