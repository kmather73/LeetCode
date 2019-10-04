class Solution {
public:
    string removeDuplicates(string s, int k) {
        deque<pair<char,int>> stack;
        for(auto ch : s)
        {
            if(stack.size() && stack.back().first == ch)
            {
                auto back = stack.back(); stack.pop_back();
                if(back.second + 1 < k)
                {
                    stack.push_back(make_pair(ch, back.second + 1));
                }
            }
            else
            {
                stack.push_back(make_pair(ch, 1));
            }
        }
        
        string str = "";
        for(auto p : stack)
        {
            for(int i = 0; i < p.second; ++i)
            {
                str.push_back(p.first);
            }
        }
        
        return str;
    }
};
