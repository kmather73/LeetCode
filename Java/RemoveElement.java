public class Solution {
    public int removeElement(int[] nums, int val) {
        int currentLength = 0;
        
        for(int i = 0; i < nums.length; ++i){
            if(nums[i] != val){
                nums[currentLength] = nums[i];
                ++currentLength;
            }
        }
        return currentLength;
    }
}
