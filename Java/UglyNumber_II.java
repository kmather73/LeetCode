public class Solution {
    public int nthUglyNumber(int n) {
        int uglyNums[] = new int[n];
        
        uglyNums[0] = 1;
        
        int index2 = 0, index3 = 0, index5 = 0;
        int count = 1;
        
        for(int i = 1; count < n; ){
            int temp2 = 2 * uglyNums[index2];
            int temp3 = 3 * uglyNums[index3];
            int temp5 = 5 * uglyNums[index5];
            
            uglyNums[i] = Math.min(temp2, Math.min(temp3, temp5));
            if(uglyNums[i] == temp2)
                ++index2;
            else if(uglyNums[i] == temp3)
                ++index3;
            else
                ++index5;
            
            if(uglyNums[i] != uglyNums[i-1]){
                ++i;
                ++count;
            }
        }
        return uglyNums[n-1];
    }
}
