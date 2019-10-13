using DP = vector<vector<vector<int>>>;
class Solution {
const int mod = 1000000007;
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        DP dp(n+1, vector<vector<int>>(6, vector<int>(16)));
        return Roll(dp, n, 0, 0, rollMax);
    }
    
    int Roll(DP &dp, int n, int index, int run, vector<int>& rollMax)
    {
        if(n <= 0) return 1;
        if(dp[n][index][run]) return dp[n][index][run];
        
        auto count = 0L;
        for(auto i = 0; i < rollMax.size(); ++i)
        {
            auto nb = 1 + run * (i == index);
            if(rollMax[i] >= nb)
            {
                count += Roll(dp, n-1, i, nb, rollMax);
            }
        }
        
        return dp[n][index][run] = count % mod;
    }
};
