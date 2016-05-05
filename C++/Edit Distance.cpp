class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
     
        std::vector< std::vector<int> > DP(n+1, std::vector<int>(m+1) );
     
        for( int i = 0; i <= n; ++i)
             DP[i][0] = i;
     
        for(int j = 0; j <= m; ++j)
            DP[0][j] = j;
        
        for(int i = 1; i <= n; ++i) { 
            for(int j = 1; j <= m; ++j) {
                int min = 1+std::min( DP[i-1][j],
                                    DP[i][j-1]);
                                 
                                 
                if(word1[i-1] == word2[j-1])
                    min = std::min( min, DP[i-1][j-1]);
                else
                    min = std::min( min, DP[i-1][j-1]+1);
                    
                DP[i][j] = min;
            }
        }
        
        return DP[n][m];
    }
};
