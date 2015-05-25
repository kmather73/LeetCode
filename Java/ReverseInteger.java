public class Solution {
    public int reverse(int x) {
        boolean isPositive = true;
        
        if(x < 0){ 
            isPositive = false;
            x = -x;
        }
        
        int reverseNum = 0;
        while(x > 0){
            if(Integer.MAX_VALUE/10 < reverseNum){
                return 0;
            }
            reverseNum = reverseNum * 10 + x % 10;// copies the current last digit of x and puts it at the end of reverseNum.
            x = x / 10; // removes the last digit of x
        }

        
        if(!isPositive){
            reverseNum = -reverseNum;
        }

        return reverseNum;
    }
}
