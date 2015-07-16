public class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] products = new int[nums.length];
        
        products[0] = 1;
        for(int i = 1; i < nums.length; ++i){
            products[i]  = products[i-1]*nums[i-1];
        }
        
        int numbersToLeft = nums[nums.length - 1];
        
        for(int i = nums.length - 2 ; i >= 0; --i){
            products[i] *= numbersToLeft;
            numbersToLeft *= nums[i];
        }
        return products;
    }
}
