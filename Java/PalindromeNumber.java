public class Solution {
    public boolean isPalindrome(int number) {
        if(number < 0){
            return false;
        }
        
        int divisor = 1;
        while(number / divisor >= 10){
            divisor *= 10;
        }
        
        int currLeftDigit  = 0;
        int currRightDigit = 0;
        
        while(number > 0){
            currLeftDigit = number / divisor;
            currRightDigit = number % 10;
            
            number = (number % divisor) / 10;//Remove the right and left most digits.
            divisor = divisor / 100;
            if(currLeftDigit != currRightDigit){
                return false;
            }
        }
        return true;
    }
}
