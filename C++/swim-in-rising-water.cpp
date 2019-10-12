class Solution {
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};    
public:
    int swimInWater(vector<vector<int>>& grid) {
        auto cmp = [&](const pair<int,int> &a, const pair<int,int> &b)
        {
            return grid[a.first][a.second] > grid[b.first][b.second];
        };
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> q(cmp); 
        q.push(make_pair(0,0));
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> used(n, vector<bool>(m));
        int maxEleSoFar = 0;
        
        while(q.size())
        {
            auto top = q.top(); q.pop();
            maxEleSoFar = max(maxEleSoFar, grid[top.first][top.second]);
            for(int i = 0; i < 4; ++i)
            {
                auto nx = top.first + dx[i];
                auto ny = top.second + dy[i];
                if(ValidMove(nx, ny, n, m) && !used[nx][ny])
                {
                    used[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
            
            if(top.first + 1 == n && top.second + 1== m) return maxEleSoFar;
        }
        return 0;
    }
    
    inline bool ValidMove(int x, int y, int n, int m)
    {
        return !(x < 0 || y < 0 || x >= n || y >= m);
    }
};
