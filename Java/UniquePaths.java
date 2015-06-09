public class Solution {
    public int uniquePaths(int m, int n) {
        int min = m < n ? m : n; 
        return binomal(m + n - 2, min - 1);
    }

    public int binomal(int n, int k){
        double ans = 1;
        while(k > 0){
            ans *= n;
            ans /= k;
            
            --n;
            --k;
        }
        return (int)Math.round(ans);
    }
}
