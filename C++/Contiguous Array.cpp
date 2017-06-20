class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp; mp[0] = -1;
        
        int len = 0;
        for(int i=0, sum=0; i < nums.size(); ++i) {
            sum += 2*nums[i]-1;
            
            if(mp.count(sum) > 0) len = max(len, i - mp[sum]);
            if(mp.count(sum) == 0) mp[sum] = i;
        }
        
        return len;
    }
};
