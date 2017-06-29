class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(const int& num : nums) {
            ++mp[num];
        }
        
        for(const auto& x: mp){
            if(x.second != 3) return x.first;
        }
        
        return 0;
    }
};
