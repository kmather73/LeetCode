void floodIsland(char** grid, int colBound, int rowBound, int row, int col);
int numIslands(char** grid, int gridRowSize, int gridColSize) {
    int count = 0;
    for(int i = gridRowSize-1; i >= 0; i--){
        for(int j = gridColSize-1; j >= 0; j--){
            if(grid[i][j] == '1'){
                ++count;
                floodIsland(grid, gridColSize, gridRowSize, i, j);
            }
        }
    }
    return count;
}

void floodIsland(char** grid, int colBound, int rowBound, int row, int col){
    if( row < 0 || col < 0 || col >= colBound || row >= rowBound || grid[row][col] == '0')
        return;
    
    grid[row][col] = '0';
    floodIsland(grid, colBound, rowBound, row - 1, col);
    floodIsland(grid, colBound, rowBound, row + 1, col);
    floodIsland(grid, colBound, rowBound, row, col - 1);
    floodIsland(grid, colBound, rowBound, row, col + 1);
}
