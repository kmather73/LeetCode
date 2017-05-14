class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        if(m==0 || n==0) return m+n;
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int i=0; i<=n; ++i) dp[i][0] = i;
        for(int j=0; j<=m; ++j) dp[0][j] = j;
        
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                int x = (word1[i-1] == word2[j-1]) ? dp[i-1][j-1] : INT_MAX;
                dp[i][j] = min(x, 1 + min(dp[i-1][j], dp[i][j-1]));
            }
        }
        
        return dp[n][m];
    
    }
};
