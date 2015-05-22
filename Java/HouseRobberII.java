public class Solution {
    public int rob(int[] nums) {
        if(nums == null || nums.length == 0){
            return 0;
        }
        else if( nums.length <= 3){//Edge cases.
                int max = nums[0] ;
                for(int i = 1; i != nums.length; ++i){//Just find the max of the given elements.
                    max = Math.max(max, nums[i]);
                }
                return max;
        }
        return Math.max(nums[0] + rob(nums, 2, nums.length - 1), rob(nums, 1, nums.length) );
    }
    
    /*The wrapper function that solves the problem via DP. "start" is the first house that we can rob from and "end" is the last house 
    * that we can rob from.
    */
    public int rob(int[] nums, int start, int end){
        int size = end - start + 1 ;//The size of the DP
        int[] values = new int[size];//Set up the DP.
        values[0] = 0;//Boundary condition. You don't rob the house at position start.
        values[1] = nums[start];//Boundary condition. You do rob the house at position start.
        
        for(int i = 2; i < size; ++i){//Let the information percolate to the right.
            values[i] = Math.max(values[i-1], values[i-2] + nums[start + i -1] ); //Which house is it better to rob from? 
        }
        return values[size-1];//return the max value that we can rob.
    }
}
