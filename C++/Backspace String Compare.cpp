class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return edit(S) == edit(T);
    }
    
    string edit(string &s)
    {
        string e;
        for(auto ch : s)
        {
            if(ch == '#') {if (e.size()) e.pop_back();}
            else e.push_back(ch);
        }
        
        return e;
    }
};
