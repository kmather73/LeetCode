class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        for(auto num: nums) ++mp[num];
        
        vector<int> v;
        for(auto p: mp) {
            if(p.second == 1) v.push_back(p.first);
        }
        
        return v;
    }
};
