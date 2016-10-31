class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int count = 0;
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(board[i][j] == 'X'){
                    sinkShip2(board, n, m, i, j);
                    ++count;
                }
            }
        }
        return count;
    }
    
    void sinkShip2(vector<vector<char>>& board, int& rows, int& cols, int i, int j){
        if(i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] != 'X') return;
        
        board[i][j] = '.';
        sinkShip2(board, rows, cols, i+1, j);
        sinkShip2(board, rows, cols, i-1, j);
        sinkShip2(board, rows, cols, i, j+1);
        sinkShip2(board, rows, cols, i, j-1);
    }
    
    /*
    void sinkShip(vector<vector<char>>& board, int i, int j){
        int n = board.size();
        int m = board[0].size();
        
        if(i+1 < n && board[i+1][j] == 'X'){
            while(i < n && board[i][j] == 'X'){
                board[i][j] = '.';
                ++i;
            }
        } else {
            while(j < m && board[i][j] == 'X'){
                board[i][j] = '.';
                ++j;
            }
        }
    }
    */
    
};
