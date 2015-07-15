public class Solution {
    public int trailingZeroes(int n) {
        int numberOfZeros = 0;
        
        while(n > 0){
            n = n/5;
            numberOfZeros += n;
        }
        return numberOfZeros;
    }
}
