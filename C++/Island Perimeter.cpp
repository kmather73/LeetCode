int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int p = 0;
        
        for(int i=0; i<grid.size(); ++i){
            for(int j = 0; j< grid[0].size(); ++j){
                if(grid[i][j] == 0){
                    for(int k =0; k<4; ++k){
                        if(i+dx[k] >= 0 && i+dx[k] < n && j+dy[k] >= 0 && j+dy[k] < m && grid[i+dx[k]][j+dy[k]] == 1){
                            ++p;
                        }
                    }
                } 
                
                if(grid[i][j] == 1 && i == 0 ) ++p;
                if(grid[i][j] == 1 && i == n-1) ++p;
                if(grid[i][j] == 1 && j == 0 ) ++p;
                if(grid[i][j] == 1 && j == m-1) ++p;
                
            }
        }
        return p;
    }
};
