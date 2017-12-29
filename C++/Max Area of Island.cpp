class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = 0;
        for(int i=0; i < grid.size(); ++i){
            for(int j=0; j < grid[0].size(); ++j){
                int n = 0;
                flood(grid, i, j, n);
                m = max(n, m);
            }
        }
        return m;
    }
    
    void flood(vector<vector<int>>& grid, int r, int c, int &count) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0) return;
        ++count;
        
        grid[r][c] = 0;
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        for(int i=0; i < 4; ++i) flood(grid, r+dy[i], c+dx[i], count);
    }
};
