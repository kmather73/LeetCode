public class Solution {
    public int[] countBits(int num) {
        int[]  bits  = new int[num+1];
        int range = 0;
        int j = 0;
        for(int i = 1; i <= num; ++i){
            if( (1<<range)  == i){
                j = 0;
                ++range;
            }
            bits[i] = 1 + bits[j];
            ++j;
        }
        return bits;
    }
}
