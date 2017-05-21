class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(const auto& x: nums) ++mp[x];
        
        int len = 0;
        for (const auto& x: mp) {
            int y = x.first;
            if (mp.count(y+1)) len = std::max(len, x.second + mp[y+1]);
            if (mp.count(y-1)) len = std::max(len, x.second + mp[y-1]);
        }
        
        return len;
    }
};
