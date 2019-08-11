class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        
        vector<vector<int>> DP(n+1, vector<int>(m+1));
        int k = 0;
        for(int i=1; i <= n; ++i)
        {
            for(int j=1; j <= m; ++j)
            {
                if(A[i-1] == B[j-1])
                {
                    DP[i][j] = 1 + DP[i-1][j-1];
                    k = max(k, DP[i][j]);
                }
            }
        }
        
        return k;
    }
};
