class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        
        while(i > 0 && nums[i] <= nums[i-1]) {
            --i;
        }
        
        if(i == 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        
        int j=n-1;
        while(i != 0 && j > i) {
            if(nums[i-1] < nums[j]) break;
            --j;
        }
        
        swap(nums[i-1], nums[j]);
        sort(nums.begin()+i, nums.end());
    }
};