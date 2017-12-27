class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int mi = 0;
        for(int i=1; i < nums.size(); ++i)
        {
            if(nums[i] > nums[mi]) mi = i;
        }
        
        int m = nums[mi];
        swap(nums[mi], nums.back());
        nums.pop_back();
        
        for(int i=0; i<nums.size(); ++i)
        {
            if(2*nums[i] > m) return -1;
        }
        
        return mi;
    }
};
