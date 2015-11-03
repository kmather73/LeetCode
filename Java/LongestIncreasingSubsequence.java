public class Solution {
    public int lengthOfLIS(int[] nums) {
        if(nums.length == 0)
            return 0;

        int[] maxSubLength = new int[nums.length];
        maxSubLength[nums.length-1] = 1;

        int ans = 0;
        for(int i = nums.length - 1; i >= 0; --i){
            int max = 1; 
            for(int j = i + 1; j < nums.length; ++j){
                if(nums[i] < nums[j])
                    max = Math.max(max, 1 + maxSubLength[j]);
            }
            maxSubLength[i] = max;
            ans = Math.max(ans,max);
        }
        return ans;
    }
}

