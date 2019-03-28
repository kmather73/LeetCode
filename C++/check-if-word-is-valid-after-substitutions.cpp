class Solution {
public:
    bool isValid(string S) {
        stack<char> s;
        for(int i=0; i < S.size(); ++i)
        {
            if(S[i] == 'a') s.push('a');
            else if(S[i] == 'b') 
            {
                if(!(s.size() && s.top() == 'a')) return false;
                
                s.pop();
                s.push('b');
                
            }
            else
            {
                if(!(s.size() && s.top() == 'b')) return false;
                s.pop();
            }
        }
        
        return s.size() == 0;
    }
};
