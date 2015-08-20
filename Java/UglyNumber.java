public class Solution {
    public boolean isUgly(int num) {
        
        if( num <= 0 || (num!= 1 && num % 2 != 0 && num % 3 != 0 && num % 5 != 0) )// Neg one 
            return false;
        
        int largetPowerOfByTwo = largerestFactorInNum(num, 2); 
        int largetPowerOfByThree = largerestFactorInNum(num, 3);
        int largetPowerOfByFive = largerestFactorInNum(num, 5); 
        return largetPowerOfByTwo * largetPowerOfByThree * largetPowerOfByFive == num; 
    }
    
    int largerestFactorInNum(int num, int factorBy){
        int factor = 1;        
        while( factor * (num / factor) == num) 
            factor *= factorBy ;
        return factor / factorBy ;
    }
}
