class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> seq;
        
        int p = 0;
        int q = S.size();
        
        for(auto ch : S)
        {
            if(ch == 'I') seq.push_back(p++);
            else seq.push_back(q--);
        }
        
        seq.push_back( (p+q) / 2);
        return seq;
    }
};
