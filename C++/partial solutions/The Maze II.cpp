// Fails the last 5 test cases... need to check by hand if test case is wrong.

int dx[4] = {0, -1, 1, 0};
int dy[4] = {1, 0, 0, -1};
string posMove[] = {"d", "l", "r", "u"};
#define MM 4
#define MAGIC 30*30+1

class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        unordered_map<int, int> dp;
        unordered_map<int,string> paths;
        bool madeIt = false;
        utill(dp, paths, ball, hole, maze, madeIt);
        
        if(!madeIt) return "impossible";
        return paths[encodeint(ball)];
        
    }
    
    int encodeint(vector<int> &pos){
        return pos[0]*1000 + pos[1];
    }
    
    int utill(unordered_map<int, int> &dp, unordered_map<int, string> &paths, vector<int> &pos, vector<int> &hole, vector<vector<int>>& maze, bool &madeIt){
        int cp = encodeint(pos);
        if( dp.count(cp) > 0) return dp[cp];
        if(hole[0] == pos[0] && hole[1] == pos[1]){
            madeIt = true;
            return 0;  
        }
        
        dp[cp] = MAGIC;
        vector<int> end(2);
        
        for(int i=0; i<MM; ++i){
            int dist = hitWall(maze, pos, dx[i], dy[i], end, hole);
            
            int move = utill(dp, paths, end, hole, maze, madeIt);
            int ep = encodeint(end);
            int total = dist + move;
            
            if(total < dp[cp] || (total <= dp[cp] && posMove[i]+paths[ep] <= paths[cp])){
                paths[cp] = posMove[i] + paths[ep];
                dp[cp] = total;
            }
        }
        
        return dp[cp];
    }
    
    int hitWall(vector<vector<int>>& maze, vector<int> &pos, int& dx, int& dy, vector<int> &end, vector<int> &hole){
        int n = maze.size();
        int m = maze[0].size();
        int y = pos[0];
        int x = pos[1];
        
        int moves = 0;
        while(!(x == hole[1] && y == hole[0]) && x+dx >= 0 && x+dx < m && y+dy >= 0 && y+dy < n && maze[y+dy][x+dx] != 1){
            x += dx;
            y += dy;
            ++moves;
        }
        
        end[1] = x;
        end[0] = y;
        return moves;
    }
};
