public class Solution {
    public int mySqrt(int x) {
        double epsilon = 0.1;
        
        double xn = x;
        double xn2 = 0.0f;
        while(Math.abs(xn - xn2) > epsilon){
            xn2 = xn;
            xn = xn + (x - xn * xn) / (2 * xn);
        }
        return (int) xn;
    }
}
