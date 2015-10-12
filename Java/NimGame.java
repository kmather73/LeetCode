public class Solution {
    public boolean canWinNim(int n) {
        return n%4 != 0;
    }
}



public class Solution {
    public boolean canWinNim(int n) {
    int[] results = new int[n+3];
        results[1] = 1;
        results[2] = 1;
        results[3] = 1;
        
        return utillCanWinNim(n,results);
    }
    
    boolean utillCanWinNim(int n, int[] results){
        if(n > 3) {
            if(results[n-1] == 1 || results[n-2] == 1 || results[n-3] == 1)
                results[n] = 1;
            else
                results[n] = -1;
        }
        return (results[n] == 1) ? true:false; 
    }
}
