class Solution {
public:
    int heightChecker(vector<int>& heights) {
        auto cpy = heights;
        sort(cpy.begin(), cpy.end());
        
        auto cnt = 0;
        for(auto i = 0; i < heights.size(); ++i)
        {
            cnt += cpy[i] != heights[i];
        }
        
        return cnt;
    }
};
