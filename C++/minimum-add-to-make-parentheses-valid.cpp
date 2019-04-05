class Solution {
public:
    int minAddToMakeValid(string S) {
        auto stack = 0;
        auto missing = 0;
        
        for(auto ch : S)
        {
            if(ch == '(') ++stack;
            else
            {
                if(stack > 0) --stack;
                else ++missing;
            }
        }
        
        return missing + stack;
    }
};
