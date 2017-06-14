class Solution {
public:
    int getPerim(int i, int j, vector<vector<int>>& grid){
        if(grid[i][j] == 0) return 0;
        
        int n = grid.size(), m = grid[0].size();
        if(n == 1 && m == 1) return 4*grid[0][0];
        int p = (i == 0) + (i+1 == n) + (j == 0) + (j+1 == m);
        
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        for(int k=0; k < 4;++k){
            if( i+dx[k] >=0 && i+dx[k] < n && j+dy[k] >= 0 && j+dy[k] < m && grid[i+dx[k]][j+dy[k]]==0) {
                ++p;
            }
        }
        
        return p;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int perim = 0;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                perim += getPerim(i, j, grid);
            }
        }
        
        return perim;
    }
};
