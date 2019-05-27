class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) 
    {
        auto n = A.size();
        auto dp = vector<int>(n);
        dp[0] = A[0];
        for(auto i = 1; i < n; ++i)
        {
            auto maxSoFar = A[i];
            dp[i] = A[i] + dp[i-1];
            for(auto j = 1; j < K && i - j >= 0; ++j)
            {
                maxSoFar = max(maxSoFar, A[i - j]);
                dp[i] = max(dp[i], maxSoFar * (j+1) + (i-j-1 >= 0 ? dp[i-j-1] : 0));
            }
        }
        
        return dp[n-1];
    }
};
