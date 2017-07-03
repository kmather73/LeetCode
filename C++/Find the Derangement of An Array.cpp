class Solution {

public:
    int findDerangement(int n) {
        int mod = 10E8 + 7;
        vector<long int> dp(n+1);
        dp[0] = 1;
        
        for(int i=2; i<=n ; ++i) {
            dp[i] = ((i-1) * (dp[i-1] + dp[i-2]))%mod;
        }
        
        return dp[n];
    }
};
