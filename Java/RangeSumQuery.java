public class NumArray {
    int[] leftSums;
    
    public NumArray(int[] nums) {
        leftSums = new int[nums.length + 1];
        
        for(int i = 1; i <= nums.length; ++i)
            leftSums[i] = nums[i-1] + leftSums[i-1];
    }

    public int sumRange(int i, int j) {
        return leftSums[j+1] - leftSums[i];
    }
}
