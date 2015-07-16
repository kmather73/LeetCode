import java.math.BigInteger;

public class Solution {
    public void rotate(int[] nums, int k) {
        k = k % nums.length;
        int numberOfCycles = gcd(k, nums.length);
        int itemsPerCycle = nums.length / numberOfCycles;
        
        for(int i = 0; i < numberOfCycles; ++i){
            swapCycleToTheRightByK(nums, k, i, itemsPerCycle);
        }
    }
    
    private void swapCycleToTheRightByK(int[] nums, int k, int index, int itemsInCycle){
        int nextPosition = index;
        int lastNum = nums[nextPosition];
        int nextNum = 0;
        
        for(int i = 0; i < itemsInCycle; ++i){
            nextPosition = (nextPosition + k) % nums.length;
            
            nextNum = nums[nextPosition];
            
            nums[nextPosition] = lastNum;
            lastNum = nextNum;
        }
        
    }
    
    private static int gcd(int a, int b) {
        BigInteger b1 = BigInteger.valueOf(a);
        BigInteger b2 = BigInteger.valueOf(b);
        BigInteger gcd = b1.gcd(b2);
        return gcd.intValue();
    }
}
