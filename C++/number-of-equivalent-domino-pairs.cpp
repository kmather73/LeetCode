class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> counts(100);
        int totalCounts = 0;
        for(auto p : dominoes)
        {
            if(p[0] > p[1]) swap(p[0], p[1]);
            totalCounts += counts[p[0] + 10*p[1]]++;
        }
        
        return totalCounts;
    }
};
