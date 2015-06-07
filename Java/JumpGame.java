// O(n) in both space and time.
public class Solution {
    public boolean canJump(int[] nums) {
        int size = nums.length;
        int lastKnowTrue = size - 1;
        boolean[] jumpable = new boolean[size];
        jumpable[size - 1] = true;
        
        for(int i = size - 2; i >= 0; --i){
            if(lastKnowTrue - i <= nums[i]){
                jumpable[i] = true;
                lastKnowTrue = i;
            }
        }
        return jumpable[0];
    }
}

//This can be simplified
public class Solution {
    public boolean canJump(int[] nums) {
        int size = nums.length;
        int lastKnowTrue = size - 1;
        boolean[] jumpable = new boolean[size];
        jumpable[size - 1] = true;
        
        for(int i = size - 2; i >= 0; --i){
            for(int j = lastKnowTrue - i; j <= nums[i] && i + j < size; ++j){
                if(jumpable[i+j]){
                    jumpable[i] = true;
                    lastKnowTrue = i;
                    break;
                }
            }
        }
        return jumpable[0];
    }
}
