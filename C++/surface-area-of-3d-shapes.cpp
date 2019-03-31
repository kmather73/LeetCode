class Solution {
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
    
    public:
    int surfaceArea(vector<vector<int>>& grid) {
        int sa = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i < n; ++i)
        {
            for(int j=0; j < m; ++j)
            {
                if(grid[i][j])
                {
                    sa += 2;
                    for(int k=0; k < 4; ++k)
                    {
                        int val = 0;
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if(ValidMode(x, y, n, m)) val = grid[x][y];
                        
                        sa += max(grid[i][j]-val, 0);
                    }
                }
            }
        }
        
        return sa;
    }
        
    
    bool ValidMode(int x, int y, int n, int m)
    {
        return x >= 0 
            && x < n
            && y >= 0
            && y < m;
    }
};
