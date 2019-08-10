class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(auto x : stones) sum += x;
        
        int m = 0;
        vector<vector<bool>> dp(1 + stones.size(), vector<bool>(1 + sum / 2));
        for(int i=0; i < stones.size(); ++i) dp[i][0] = true; 
        for(int j = 1; j <= sum / 2; ++j)
        {
            for(int i=1; i <= stones.size(); ++i)
            {
                if(dp[i-1][j] || stones[i-1] <= j && dp[i-1][j-stones[i-1]])
                {
                    dp[i][j] = true;
                    m = max(m, j);
                }
            }
        }
        
        return sum - 2*m;
    }
};
