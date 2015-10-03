public class Solution {
    public void gameOfLife(int[][] board) {
        int[][] directions ={{1,-1}, {1,0}, {1,1}, {0,-1}, {0,1}, {-1,-1}, {-1,0}, {-1,1}};
        
        for(int i = 0; i < board.length; ++i)
        {
            for(int j = 0; j < board[0].length; ++j)
            {
                int live=0;
                for(int[] dir:directions)
                {
                    if(dir[0] + i < 0 || dir[0] + i >= board.length || dir[1] + j < 0 || dir[1] + j >= board[0].length) 
                        continue;
                    
                    if(board[dir[0]+i][dir[1]+j] >= 1)
                        ++live;
                }
        
                if(board[i][j] == 0 && live == 3) 
                    board[i][j] = -1;
                
                if(board[i][j] == 1 && (live < 2 || live > 3) ) 
                    board[i][j] = 2;
            }
        }
        
        for(int i = 0; i < board.length; ++i)
        {
            for(int j = 0; j < board[0].length; ++j)
            {
                if(board[i][j] == -1) 
                    board[i][j] = 1;
                    
                if(board[i][j] == 2) 
                    board[i][j] = 0;
            }
        }
    }
}
