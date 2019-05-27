class Solution {
public:
    string removeDuplicates(string &S) {
        string s = "";
        int i = 0, n = S.size();
        while(i < n)
        {
            if(s.size() && s.back() == S[i])
            {
                s.pop_back();
            }
            else
            {
                s.push_back(S[i]);
            }
            ++i;
        }
        return s;
    }
};
