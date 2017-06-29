class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m;
        if( n == 0 ) return 0;
        
        m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        grid[n-1][m-1] = grid[n-1][m-1];
        return runMemo(dp, grid, 0, 0);
    }
    
    
    int runMemo(vector<vector<int>> &dp, vector<vector<int>>& grid, int i, int j) {
        if(i+1 == grid.size() && j+1 >= grid[i].size()) return grid[i][j];
        if(i >= grid.size() || j >= grid[i].size()) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = runMemo(dp, grid, i+1, j);
        int right = runMemo(dp, grid, i, j+1);
        
        int cost = min(down, right);
        if(cost != INT_MAX) cost += grid[i][j];
        
        
        dp[i][j]  = cost;
        return cost;
    }
};
