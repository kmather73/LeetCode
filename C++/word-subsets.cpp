class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        unordered_map<int, int> bMax;
        
        for(auto b : B)
        {
            unordered_map<int, int> curr;
            for(auto ch : b) ++curr[ch];
            
            for(auto p : curr) bMax[p.first] = max(bMax[p.first], p.second);
        }
        
        vector<string> uni;
        for(auto a : A)
        {
            unordered_map<int, int> curr;
            for(auto ch : a) ++curr[ch];
            
            auto isUni = true;
            for(auto p : bMax)
            {
                if(p.second > curr[p.first]) isUni = false;
            }
            
            if(isUni) uni.push_back(a);
        }
        
        return uni;
    }
};
