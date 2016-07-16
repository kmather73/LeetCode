class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp = vector<vector<int>>(n+1 , vector<int>(n+1, INT_MAX));
        
        for(int i = 1; i <= n; ++i){
            dp[i][i] = 0;
            dp[i-1][i] = i-1;
        }
        
        
        for(int d = 2; d <= n; ++d){
            for(int i = 1; i+d <= n; ++i){
                int j = i+d;
                dp[i][j] = min(dp[i][j-1]+j, dp[i+1][j]+i);
                
                for(int k = i+1; k < j; ++k){
                    dp[i][j] = min(dp[i][j], k+max(dp[i][k-1], dp[k+1][j]));
                }
                
            }
        }
        return dp[1][n];
    }
};
