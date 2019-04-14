class Solution {
    vector<int> dp;
public:
    Solution() {
        dp = vector<int>(1001);
        dp[1] = 1;
    }
    
    bool divisorGame(int N) {
        if(dp[N]) return dp[N] == 2;
        
        dp[N] = 1;
        for(int i = N-1; i > 0; --i)
        {
            if(N % i == 0 && !divisorGame(N-i)) return dp[N] = 2;
        }
        
        return false;
    }
};
