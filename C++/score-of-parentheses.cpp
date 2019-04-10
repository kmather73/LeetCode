class Solution {
public:
    int scoreOfParentheses(string S) {
        int stack=0;
        int up=0, down=0;
        int score = 0;
        for(auto ch : S)
        {
            if(ch == '(')
            {
                ++stack;
                ++up;
            }
            else if(ch == ')')
            {
                --stack;
                if(up) score += 1 << stack;
                
                up = 0;
            }
        }
        
        return score;
    }
};
