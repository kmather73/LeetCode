class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        unordered_map<int, int> mp;
        int max = 0;
        
        for(int i=0; i < nums.size(); ++i) {
            max = std::max(max, dfs(i, nums, mp));
        }
        
        return max;
    }
    
    int dfs(int k, vector<int> &nums, unordered_map<int,int> &mp) {
        if(mp.count(k)) return 0;
        
        mp[k] = 0;
        mp[k] = 1+dfs(nums[k], nums, mp);
        
        return mp[k];
    }
};
