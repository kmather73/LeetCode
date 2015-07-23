class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if(length == 0)
            return 0;
        
        int count {1};
        for(int i = 1; i < length; ++i){
            if(nums[i-1] != nums[i])
                nums[count++] = nums[i];
        }
        return count;
    }
};
