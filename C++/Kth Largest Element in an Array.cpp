class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto kth = nums.end()-k;
        nth_element(nums.begin(), kth, nums.end());
        return *kth;
    }
};
