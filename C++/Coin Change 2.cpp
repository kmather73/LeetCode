class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1);
        dp[0] = 1;
        
        sort(coins.begin(), coins.end());
        for(int coin : coins){
            for(int i=coin; i <= amount; ++i){
                dp[i] += dp[i-coin];
            }
        }
        
        return dp[amount];
    }
};