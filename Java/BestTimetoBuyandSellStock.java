//Fatster version.
public class Solution {
    public int maxProfit(int[] prices) {
      if(prices == null || prices.length == 0){
          return 0;
      }
      
      int bestDeal = prices[0];
      int profit = 0;
      
      for(int i = 1; i < prices.length; ++i){
          bestDeal = bestDeal < prices[i] ? bestDeal : prices[i];
          profit = profit > prices[i] - bestDeal ? profit : prices[i] - bestDeal;
      }
      return profit > 0 ? profit : 0 ;
    }
}

// Cleaner version.
public class Solution {
    public int maxProfit(int[] prices) {
      if(prices == null || prices.length == 0){
          return 0;
      }
      
      int bestDeal = prices[0];
      int profit = 0;
      
      for(int i = 1; i < prices.length; ++i){
          bestDeal = Math.min(bestDeal, prices[i]);
          profit = Math.max(profit , prices[i] - bestDeal);
      }
      return profit;
    }
}
