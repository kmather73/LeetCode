class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        nums.insert(nums.begin(), 0);
        for(int i=1; i<nums.size(); ++i) nums[i] += nums[i-1];
        
        for(int i=0; i+1 < nums.size(); ++i){
            for(int j=i+2; j < nums.size(); ++j){
                if(k != 0 && (nums[j] - nums[i]) % k == 0) return true;
                if(k == 0 && nums[j] - nums[i] == 0) return true;
            }
        }
        return false;
    }
};
