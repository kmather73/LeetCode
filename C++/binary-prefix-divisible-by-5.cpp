class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> div;
        auto num = 0;
        for(auto a : A)
        {
            num *= 2;
            num += a;
            num %= 5;
            div.push_back(!num);
        }
        
        return div;
    }
};
