//Newer version using only bit tricks for a little bit more preformance.
public class Solution {
    public int numSquares(int n) {
        int m = n;
        while( (m&3) == 0 ) // m % 4 == 0
            m = m>>2;       // m = m / 4
        if( (m&7) == 7)     // m % 8 == 7
            return 4;
        
        int sqrtOfn = (int) Math.sqrt(n);
        if(sqrtOfn * sqrtOfn == n)//Is it a Perfect square?
            return 1;
            
        for(int i = 1; i <= sqrtOfn; ++i){
            int remainder = n - i*i;
            int sqrtOfNum = (int) Math.sqrt(remainder);
            if(sqrtOfNum * sqrtOfNum == remainder)
                return 2;
            }
         return 3;
    }
}

//Older version
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
