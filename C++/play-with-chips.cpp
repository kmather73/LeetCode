class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        vector<int> t {0, 0};
        for(auto chip : chips) ++t[chip%2];
        
        return min(t[0], t[1]);
    }
};
