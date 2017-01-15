class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        for(int i=0; i<nums.size(); ++i){
            int m = 0;
            while(i<nums.size() && nums[i] == 1) {
                ++m; ++i;
            }
            
            count = max(count, m);
            while(i<nums.size() && nums[i] != 0) ++i;
        }
        
        return count;
    }
};
