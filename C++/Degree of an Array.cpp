class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> map;
        
        int m = 0;
        for(int i=0; i < nums.size(); ++i){
            map[nums[i]].push_back(i);
            m = max(m, int(map[nums[i]].size()));
        }
        
        int d = nums.size();
        for(auto x : map) {
            if(x.second.size() == m)
                d = min(d, x.second.back() - x.second[0] + 1);
        }
        
        return d;
    }
};
