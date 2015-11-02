public class Solution {
    public void wiggleSort(int[] nums) {
        if (nums == null || nums.length <= 1) 
            return;
         
        for (int i = 0; i < nums.length - 1; ++i) {
            if( (i&1) == 0 && nums[i] > nums[i + 1])
                swap(nums, i, i + 1);
            else if(nums[i] < nums[i + 1]) 
                    swap(nums, i, i + 1);
        }
    }
     
    public void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
