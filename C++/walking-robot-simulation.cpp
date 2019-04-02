class Solution {
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
    
    public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, unordered_map<int,int>> obs;
        
        for(int i=0; i < obstacles.size(); ++i)
        {
            obs[obstacles[i][0]][obstacles[i][1]] = 1;
        }
        
        int x=0, y=0;
        int dir = 0;
        auto maxDist = 0;
        for(auto c : commands)
        {
            if(c >= 1 && c <= 9)
            {
                Move(x, y, c, dir, obs);
            } 
            else if(c == -1)
            {
                dir = (dir + 1) % 4;
            }
            else if(c == -2)
            {
                dir = (dir + 3) % 4;
            }
            maxDist = max(maxDist, x*x + y*y);
        }
        return maxDist;
    }
    
    void Move(int &x, int &y, int c, int dir, unordered_map<int, unordered_map<int,int>> &obs)
    {
        while(c && CanMoveTo(x + dx[dir], y + dy[dir], obs))
        {
            x += dx[dir];
            y += dy[dir];
            --c;
        }
    }
    
    inline bool CanMoveTo(int x, int y, unordered_map<int, unordered_map<int,int>> &obs)
    {
        return !(obs.count(x) && obs[x].count(y));
    }
};
