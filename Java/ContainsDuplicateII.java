public class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashMap<Integer, Integer>  numberToIndex = new HashMap<Integer, Integer>();
        for(int i = 0; i < nums.length; ++i){
            if(numberToIndex.containsKey( nums[i])){
                int distince = i - numberToIndex.get(nums[i]);
                if(distince <= k){
                    return true;
                }
            }
            numberToIndex.put(nums[i], i);
        }
        return false;
    }
}
