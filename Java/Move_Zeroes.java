public class Solution {
    public void moveZeroes(int[] nums) {
        int numOfZeros = 0;
        int left = 0;
        int right = 0;
        
        for( ; right < nums.length; ++right){
            while(right < nums.length && nums[right] == 0){
                ++numOfZeros;
                ++right;   
            }
            if(right < nums.length)
                nums[left++] = nums[right];
        }
        while(left < nums.length)
            nums[left++] = 0;
    }
}
