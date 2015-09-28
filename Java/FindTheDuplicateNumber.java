public class Solution {
    public int findDuplicate(int[] nums) {
        int fast = 0;
        int slow = 0;
        
        while(true){
        slow = nums[slow];
        fast = nums[nums[fast]];
        
        if(slow == fast)
            break;
        }
        
        fast = 0;
        while(fast!= slow){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
}

////Below only works for numbers in the range of 1 to 64 by using an int as a bit array.
long bits = 0;
        long seen = 0;
        long current = 0;
        int sum = 0;
        
        for(int num : nums){
            current = 1L<<(num-1);
            bits ^= current;
            seen |= current;
            sum += num;
        }
        
        current = 1L;
        //The dup num appers an even number of times.
        for(int i = 1; i <= nums.length; ++i){
            if( (bits & current) == 0 && (seen & current) == 1)
                return i;
            current *= 2;
        }
        
        //The dup num appersan odd number of times.
        int count = 0;
        for(int i = 1; i <= nums.length; ++i){
            if((seen & (1<<(i-1))) != 0){
                sum -= i;
                ++count;
            }
        }
        if(count == nums.length)
            return 42;
        return sum/(nums.length - count);
            
    }
