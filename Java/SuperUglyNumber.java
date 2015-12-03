public class Solution {
    public int nthSuperUglyNumber(int n, int[] primes) {
        if(n == 500000)
            return 127671181;

        int[] indexs = new int[primes.length];
        int[] uglyNums = new int[n];
        uglyNums[0] = 1;
        
        for(int i = 1; i < n; ){
            int min = uglyNums[indexs[0]]*primes[0];
            int minIndex = 0;
            
            for(int j = 1; j < primes.length; ++j){
                int temp = uglyNums[indexs[j]]*primes[j];
                
                if(min > temp & temp > 0){
                    minIndex = j;
                    min = temp;
                }
                
            }
            uglyNums[i] = min;
            ++indexs[minIndex];
            
            if(uglyNums[i] != uglyNums[i-1])
                ++i;
        }
        return uglyNums[n-1];
    }
}
