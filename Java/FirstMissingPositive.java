public class Solution {
    public int firstMissingPositive(int[] nums) {
        
        int upperBound = nums.length;
        int index = partitionPositiveNumbersLessThan(nums, upperBound);
        
        cycleSort(nums, index);
        
        int missingNumber = index + 1;
        
        for(int i = 0; i < index; ++i){
            if(nums[i] != i + 1){
                missingNumber = i + 1;
                return missingNumber;
            }
        }
        return missingNumber;
    }
    
    public int partitionPositiveNumbersLessThan(int [] nums, int upperBound){
        int index = 0;
        for(int i = 0; i < nums.length; ++i){
            if(nums[i] > 0 && nums[i] <= upperBound){
                swap(nums, i, index);
                ++index;
            }
        }
        return index;
    }

    public void swap(int[] nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    public void cycleSort(int[] nums, int sortUpToPosition){
        for(int i = 0; i < sortUpToPosition; ++i){
            while(i + 1 != nums[i] && nums[i] > 0 && nums[i] < nums.length && nums[i] != nums[nums[i]-1])
                swap(nums, i, nums[i] - 1);
        }
    }
}
