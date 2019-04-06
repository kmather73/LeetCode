class Solution {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    const char ch = 'O';
    
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0) return;
        int m = board[0].size();
        
        for(int i=0; i < n; ++i)
        {
            if(board[i].front() == ch) Color(board, i, 0, n, m);
            if(board[i].back() == ch) Color(board, i, m-1, n, m);
        }
        
        for(int j=1; j < m-1; ++j)
        {
            if(board.front()[j] == ch) Color(board, 0, j, n, m);
            if(board.back()[j] == ch) Color(board, n-1, j, n, m);
        }
        
        for(int i=0; i < n; ++i)
        {
            for(int j=0; j < m; ++j)
            {
                if(board[i][j] == 'Y') board[i][j] = ch;
                else if(board[i][j] == ch) board[i][j] = 'X';
            }
        }
    }
    
    void Color(vector<vector<char>>& board, int i, int j, int n, int m)
    {
        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] != ch) return;
        
        board[i][j] = 'Y';
        
        for(int k=0; k < 4; ++k)
        {    
            Color(board, i + dx[k], j + dy[k], n,  m);
        }
    }
};
