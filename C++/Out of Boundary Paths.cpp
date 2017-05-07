class Solution {
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0 ,0};

public:
    long findPaths(int m, int n, int N, int i, int j) {
        int mod = (10E8) + 7;
        vector<vector<vector<long>>> dp(m, vector<vector<long>>(n, vector<long>(2)));
        
        for(int i=0; i<m; ++i){
            ++dp[i][0][1];
            ++dp[i][n-1][1];
        }
        
        for(int j=0; j<n; ++j){
            ++dp[0][j][1];
            ++dp[m-1][j][1];
        }
        
        
        for(int k=2; k<=N; ++k){
            for(int i=0; i<m; ++i){
                for(int j=0; j<n; ++j){
                    dp[i][j][k%2] = 0;
                    for(int t=0; t<4; ++t){
                        if(outOfBounds(m,n, i+dx[t], j+dy[t])){
                            dp[i][j][k%2] = (dp[i][j][k%2]+1L) % mod;
                        } else {
                            dp[i][j][k%2] = (dp[i][j][k%2] + dp[i+dx[t]][j+dy[t]][(k-1)%2]) % mod;
                        }
                    }
                }
            }
        }
        
        return dp[i][j][N%2] % mod;
    }
    
    bool outOfBounds(int m, int n, int i, int j){
        return i < 0 || j < 0 || i >= m || j >= n;
    }
};
