class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) return 0;
        unordered_map<int,int> counts;
        
        for(int x : nums) ++counts[x];
        
        int sum = 0;
        for(const auto& p: counts) {
            if(k != 0) sum += (counts.count(p.first+k) > 0);
            
            else sum += p.second > 1;
        }
        return sum;
    }
};
