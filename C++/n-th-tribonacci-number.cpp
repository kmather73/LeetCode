class Solution {
unordered_map<int,int> dp;
    
    public:
    Solution()
    {
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
    }
    
    int tribonacci(int n) {
        if(dp.count(n)) return dp[n];
        
        return dp[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
};
