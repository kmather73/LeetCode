public class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        if(m == 0 || m == n)
            return m;
        
        int logM = (int) (Math.log(m) / Math.log(2));
        int logN = (int) (Math.log(n) / Math.log(2));
        
        if(logM != logN)
            return 0;
        else
            return (1<<logM) + rangeBitwiseAnd(m-(1<<logM) , n-(1<<logM));
    }
}
