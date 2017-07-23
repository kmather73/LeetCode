class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num: nums) ++mp[num];
        
        vector<int> v;
        int a, b;
        for(int i=1; i <= nums.size(); ++i) {
            
            if(mp[i] == 2) a = i;
            if(mp[i] == 0) b = i;
            
        }
        
        return {a, b};
    }
};
