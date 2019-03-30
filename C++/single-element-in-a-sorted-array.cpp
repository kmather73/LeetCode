class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left < right)
        {
            auto n = (right - left) / 2 + left;
            
            if(n%2) --n;
            
            if(nums[n] == nums[n+1]) left = n + 2;
            else right = n;   
        }
        return nums[left];
    }
};
