public class Solution {
    public int coinChange(int[] coins, int amount) {
        Arrays.sort(coins);
        HashMap<Integer,Integer> dp = new HashMap<Integer, Integer>();
        dp.put(0,0);
        
        return coinChange(coins, amount, dp);
    }
    
    public int coinChange(int[] coins, int amount, HashMap<Integer,Integer> dp){
        if(dp.containsKey(amount)){
            return dp.get(amount);
        } else if(amount < coins[0]){
            dp.put(amount, -1);
            return -1;
        }
        
        int min = Integer.MAX_VALUE;
        for(int i=0; i<coins.length; ++i) {
            int temp = coinChange(coins, amount - coins[i], dp);
            
            if(temp >= 0)
                min = Math.min(min, temp+1);
        }
        
        if(min == Integer.MAX_VALUE)
            min = -1;
        dp.put(amount, min);
        
        return min;
    }
}
