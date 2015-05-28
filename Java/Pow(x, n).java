public class Solution {
    public double myPow(double x, int n) {
        if(n == 0){//Base case.
            return 1;
        }
        
        boolean isNegative = false;
        if(n < 0){
            n = -n;
            isNegative = true;
        }
        
        double ans = myPow(x, n/2);
        ans = ans * ans;
        if(n % 2 != 0){
           ans = ans * x;
        }
        
        if(isNegative){
            ans = 1/ans;
        }
        return ans;
    }
}
