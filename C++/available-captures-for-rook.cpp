class Solution {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int i=0, j=0;
        for(; board.size(); ++i)
        {
            for(j=0; j < board[0].size(); ++j)
            {
                if(board[i][j] == 'R') goto found;
            }
        }
        
        found:
        
        int pawns = 0;
        for(int k=0; k < 4; ++k)
        {
            int d = 1;
            auto nx = i+d*dx[k];
            auto ny = j+d*dy[k];
            while(nx >= 0 && nx < 8 &&
                  ny >= 0 && ny < 8)
            {
                if(board[nx][ny] != '.')
                {
                    pawns += board[nx][ny] == 'p';
                    break;
                }
                
                ++d;
                nx = i+d*dx[k];
                ny = j+d*dy[k];
            }
            
        }
        return pawns;
    }
};
