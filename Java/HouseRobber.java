public class Solution {
    public int rob(int[] num) {
        if(num == null || num.length <1){//Edge case.
            return 0;
        }
        
        int[] values = new int[num.length+1];//Set up the DP. The value in values[i] is the max amount of money that can be robbed from the first i houses. 
        values[0] = 0;//Boundary condition. You don't rob the first house.
        values[1] = num[0];//Boundary condition. You do rob the first house.
        
        for(int i = 2; i <= num.length; i++){//Let the information percolate to the right.
            values[i] = Math.max(values[i-1], values[i-2] + num[i-1] ); //Is it better to rob from house i or not 
        } 
        return values[num.length];//return the max value that we can rob.
    }
}
