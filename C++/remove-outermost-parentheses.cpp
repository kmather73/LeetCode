class Solution {
public:
    string removeOuterParentheses(string S) {
        int stack;
        string str;
        for(auto ch : S)
        {
            if(!((ch == ')' && stack == 1) || (ch == '(' && stack == 0)))
            {
                str.push_back(ch);
            }
            
            if(ch == ')') --stack;
            else if(ch == '(') ++stack;           
        }
        
        return str;
    }
};
