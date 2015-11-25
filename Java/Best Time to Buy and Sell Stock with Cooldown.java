public class Solution {
    public int maxProfit(int[] prices) {
        int[] profit = new int[prices.length + 2];
        int[] moreProfit = new int[prices.length + 2];
        
        for(int i = prices.length-1; i>= 0; --i){
            profit[i] = profit[i+1];
            for(int j = i + 1; j < prices.length; ++j)
                profit[i] = Math.max(profit[i], profit[j+2] + prices[j] - prices[i]);
       }
        return profit[0];
    }
}
