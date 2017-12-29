class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size()-1;
        nums.push_back(0);
        for(int i=n; i>= 0; --i){
            nums[i] += nums[i+1];
        }
        
        for(int i=0; i <= n; ++i)
        {
            if(nums[i] == nums[0] - nums[i+1]) return i;
        }
        return -1;
    }
};
