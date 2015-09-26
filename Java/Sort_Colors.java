public class Solution {
    public void sortColors(int[] nums) {
        int[] counts = new int[3];
        
        for(int col : nums)
            ++counts[col];
        
        int position = 0;
        for(int i = 0; i < 3; ++i)
            while(counts[i]-- > 0)
                nums[position++] = i;
    }
}
