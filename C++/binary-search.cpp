class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        
        while(left <= right)
        {
            int mid = (right - left) / 2 + left;
            if(nums[mid] < target) left = mid + 1;
            else if(nums[mid] > target) right = mid - 1;
            else return mid;
        }
        
        return -1;
    }
};
