class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> pXz(n);
        vector<int> pYz(n);
        int nonZero = 0;
        for(int y=0; y < n; ++y)
        {
            for(int x = 0; x < n; ++x)
            {
                pXz[x] = max(pXz[x], grid[y][x]);
                pYz[y] = max(pYz[y], grid[y][x]);
                nonZero += grid[y][x] != 0;
            }
        }
        
        return accumulate(pXz.begin(), pXz.end(), 0) 
            + accumulate(pYz.begin(), pYz.end(), 0)
            + nonZero;
    }
};
