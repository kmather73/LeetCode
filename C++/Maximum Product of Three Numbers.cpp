class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size()-1;
        int a = nums[n], b = nums[n-1], c = nums[n-2];
        int d = nums[0], e = nums[1], f = nums[2];
        
        return max(a*b*c, max(a*d*e, d*e*f));
    }
};