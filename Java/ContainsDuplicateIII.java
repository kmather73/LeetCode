public class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        if(nums.length == 0 || k <= 0){
            return false;
        }
        
        TreeSet<Integer> lastKNumbers = new TreeSet<Integer>();
        lastKNumbers.add(nums[0]);
        
        Integer nextLargest = 0;
        Integer nextSmallest = 0;
        
        for(int i = 1; i < nums.length; ++i){
            Integer currentNumber = nums[i];
            nextLargest = lastKNumbers.ceiling(currentNumber);
            nextSmallest = lastKNumbers.floor(currentNumber);
        
            if((nextLargest != null && Math.abs(nums[i] - (long) nextLargest) <= t) 
                || (nextSmallest != null && Math.abs(nums[i] - (long) nextSmallest) <= t)){
                return true;
            }
            if(lastKNumbers.size() == k){
                lastKNumbers.remove(nums[i - k]);
            }
            lastKNumbers.add(nums[i]);
        }
        return false;
    }
}
