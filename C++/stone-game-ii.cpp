class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int>(n + 1));
        
        for(int i=1; i < n; ++i) piles[i] += piles[i-1];
        piles.insert(piles.begin(), 0);
        
        return DP(dp, 1, 1, piles);
    }
    
    int DP(vector<vector<int>> &dp, int M, int i, vector<int> & piles)
    {
        if(i >= dp.size()) return 0;
        if(dp[i][M] != 0) return dp[i][M];
        
        auto limit = min(2*M + i, (int)piles.size());
        for(int j = i; j < limit; ++j)
        {
            auto sum = piles[i] - piles[i-1];
            auto remSum = piles.back() - piles[i];
            dp[i][M] = max(dp[i][M], sum + remSum - DP(dp, max(M, j+1-i), j+1, piles));
        }
        
        return dp[i][M];
    }
};
