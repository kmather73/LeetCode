class Solution {
public:
    string toGoatLatin(const string &S) {
        string str = "";
        string ending = "a";
        int i = 0;
        
        while(i < S.length())
        {
            char ch = S[i];
            str += GetPrefix(ch);
            ++i;
            while(i < S.length() && S[i] != ' ')
            {
                str += S[i];
                ++i;
            }
            
            str += GetSufix(ch);
            str += ending; 
            
            if(i < S.length())
            {
                ending += "a";    
                str += " ";
            }
            ++i;
        }
        
        return str;
    }
    
    bool IsVowel(char c){
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    string GetSufix(char ch){
        if(!IsVowel(ch)) return string(&ch, 1) + "ma";
        return "ma";
    }
    
    string GetPrefix(char ch){
        if(IsVowel(ch)) return string(&ch, 1);
        return "";
    }
};
