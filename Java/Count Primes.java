public class Solution {
    public int countPrimes(int n) {
        if(n <= 1)
            return 0;
        
        boolean[] notPrime = new boolean[n];
        
        for (int i = 2; i * i < n; ++i) {
            if (notPrime[i]) 
                continue;
            for (int j = i * i; j < n; j += i)
                notPrime[j] = true;
        }
        
        int count = n - 2;
        for (int i = 2; i < n; i++)
            if (notPrime[i]) 
                --count;
        return count;
    }
}
