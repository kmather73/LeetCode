class Solution {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int minutes = 0;
        while(true)
        {
            int oldRotten = 0;
            int newRotten = 0;
            for(int i=0; i < n; ++i)
            {
                for(int j=0; j < m; ++j)
                {
                    if(grid[i][j] == 2)
                    {
                        ++oldRotten;
                        for(int k=0; k < 4; ++k)
                        {
                            auto nx = i + dx[k];
                            auto ny = j + dy[k];
                            if(nx >= 0 && nx < n && ny >=0 && ny < m && grid[nx][ny] == 1)
                            {
                                grid[nx][ny] = 3;
                                ++newRotten;
                            }
                        }
                    }
                }
            }
         
            int fresh = 0;
            for(int i=0; i < n; ++i)
            {
                for(int j=0; j < m; ++j)
                {
                    if(grid[i][j] == 3) grid[i][j] = 2;
                    else if(grid[i][j] == 1) ++fresh;
                }
            }
            
            if(newRotten == 0)
            {
                return fresh == 0 ? minutes: -1;
            }
            
            ++minutes;
        }
    }
};
