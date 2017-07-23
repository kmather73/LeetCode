class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        vector<vector<int>> isPal(n+1, vector<int>(n+1, -1));
        
        for(int i=0 ; i < n; ++i) {
            dp[i][i] = 1;
            isPal[i][i] = true;
        }
        
        for(int i=0; i < n; ++i) {
            for(int j=i+1; j < n; ++j) {
                fillPal(isPal, i, j, s);
            }
        }
        
        
        return countPal(dp, isPal, 0, n-1, s);
    }
    
    int fillPal(vector<vector<int>> &isPal, int i, int j, string &s){
        
        if(isPal[i][j] != -1) return isPal[i][j];
        
        isPal[i][j] =  s[i] == s[j];
        if(i <= j && isPal[i][j]) isPal[i][j] &= fillPal(isPal, i+1,j-1, s);
        
        return isPal[i][j];
    }
    
    int countPal(vector<vector<int>> &dp, vector<vector<int>> &isPal, int i, int j, string &s){
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        
        dp[i][j] = countPal(dp, isPal, i, j-1, s) +
                    countPal(dp, isPal, i+1, j, s) -
                    countPal(dp, isPal, i+1, j-1, s) +
                    isPal[i][j];
                    ;
        
        return dp[i][j];
    }
};
