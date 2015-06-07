public class Solution {
    public int maxSubArray(int[] nums) {
      int maxSum = Integer.MIN_VALUE;
      int runningSum = 0;
      
      for(int i = 0; i < nums.length; ++i){
          if(runningSum + nums[i] < 0){
              runningSum = 0;
          }
          else{
              runningSum += nums[i];
          }
          maxSum = Math.max(maxSum, runningSum);
      }
      
      if(maxSum == 0 && runningSum <= 0){// All numbers are negative, find the smallest one.
          maxSum = findMax(nums);
      }
      return maxSum;
    }
    
    public int findMax(int[] nums){
        int max = Integer.MIN_VALUE;;
        
        for(int i = 0; i < nums.length; ++i){
            max = Math.max(max, nums[i]);
        }
        return max;
    }
}
