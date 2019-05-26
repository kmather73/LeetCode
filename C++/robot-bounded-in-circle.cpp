class Solution {
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
    
    public:
    bool isRobotBounded(string instructions) {
        auto p = vector<int>(2);
        auto rotation = 0;
        
        for(auto ch : instructions)
        {
            if(ch == 'G')
            {
                p[0] += dx[rotation];
                p[1] += dy[rotation];
            }
            else if(ch == 'R')
            {
                rotation = (rotation + 1) % 4;
            }
            else
            {
                rotation = (rotation + 3) % 4;
            }
        }
        
        return (p[0] == 0 && p[1] == 0) || rotation;
        
    }
};
