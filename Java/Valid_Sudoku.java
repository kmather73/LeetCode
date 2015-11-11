public class Solution {
    public boolean isValidSudoku(char[][] board) {
        return validCols(board) && validRows(board) && validBlocks(board);
    }
    
    private boolean validRows(char[][] board){
        boolean[] rowNumbers = new boolean[board.length];
        boolean isValid = true;
        
        for(int i = 0; isValid && i < board.length; ++i){
            for(int j = 0; isValid && j < board[0].length; ++j){
                char c = board[i][j];
                if(c == '.')
                    continue;
                else if(!rowNumbers[c - '1'])
                    rowNumbers[c - '1'] = true;
                else
                    isValid = false;
            }
            for(int j = 0; isValid && j < board.length; ++j)
                rowNumbers[j] = false;
        }
        return isValid;
    }//End vaildRows.
    
    private boolean validCols(char[][] board){
        boolean[] colNumbers = new boolean[board.length];
        boolean isValid = true;
        
        for(int j = 0; isValid && j < board[0].length; ++j){
            for(int i = 0; isValid && i < board.length; ++i){
                char c = board[i][j];
                if(c == '.')
                    continue;
                else if(!colNumbers[c - '1'])
                    colNumbers[c - '1'] = true;
                else
                    isValid = false;
            }
            for(int i = 0; isValid && i < board.length; ++i)
                colNumbers[i] = false;
        }
        return isValid;
    }//End validCols. 
    
    private boolean validBlocks(char[][] board){
        boolean blockNumbers[] = new boolean[board.length];
        boolean isValid = true;
        
        for(int i = 0; isValid && i < 3; ++i){
            for(int j = 0; isValid && j < 3; ++j){
                for(int k = 0; isValid && k < 3; ++k){
                    for(int m = 0; isValid && m < 3; ++m){
                        char c = board[k + 3*i][m + 3*j];
                        if(c == '.')
                            continue;
                        else if(!blockNumbers[c- '1'])
                            blockNumbers[c-'1'] = true;
                        else
                            isValid = false;
                    }
                }
                
                for(int k = 0; isValid && k < 9; ++k)
                    block[k] = false;
            }
        }
        return isValid;
    }//End validBlocks.
}
