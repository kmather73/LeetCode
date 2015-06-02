public class Solution {
    public int singleNumber(int[] nums) {
        int missingNumber = 0;
        
        for(int i = 0; i < nums.length; ++i){
            missingNumber ^= nums[i];
        }
        return missingNumber;
    }
}
