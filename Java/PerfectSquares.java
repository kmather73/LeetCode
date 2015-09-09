public class Solution {
    public int numSquares(int n) {
        int m = n;
        while( m % 4 == 0 )
            m = m>>2;
        if(m % 8 == 7)
            return 4;
        
        int sqrtOfn = (int) Math.sqrt(n);
        if(sqrtOfn * sqrtOfn == n)//Is it a Perfect square?
            return 1;
        else{
                for(int i = 1; i <= sqrtOfn; ++i){
                    int remainder = n - i*i;
                    int sqrtOfNum = (int) Math.sqrt(remainder);
                    if(sqrtOfNum * sqrtOfNum == remainder)
                        return 2;
                }
            }
         return 3;
    }
}
