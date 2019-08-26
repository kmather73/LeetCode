struct Move
{
    int dx;
    int dy;
};

class Solution {
    vector<Move> Moves { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j]) q.push(make_pair(i, j));
            }
        }
        
        int i = 1, d = -1;
        while(q.size())
        {
            queue<pair<int, int>> nextQ;
            while(q.size())
            {
                auto pair = q.front(); q.pop();
                auto x = pair.first;
                auto y = pair.second;
            
                for(auto &M : Moves)
                {
                    auto nextX = x + M.dx;
                    auto nextY = y + M.dy;
                    if(ValidMove(nextX, nextY, n) && !grid[nextX][nextY])
                    {
                        grid[nextX][nextY] = i;
                        nextQ.push(make_pair(nextX, nextY));
                        d = i;
                    }
                }
            }
            
            swap(q, nextQ);
            ++i;
        }
        
        return d;
    }
    
    inline bool ValidMove(int x, int y, int n)
    {
        return x >= 0 && y >= 0 && x < n && y < n;
    }
};
