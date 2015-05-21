public class Solution {
    //simple class to represent where a position in a n*m board.
    public class position{
        int row;
        int col;
        position(){row = 0; col = 0;}
        position(int x, int y){row = x; col = y;}
    }
    
    public boolean exist(char[][] board, String word) {
        if(word == null || word == ""){
            return true;
        }
        else if (board == null){
            return false;
        }

        HashMap<Character,List<position>> index = buildIndex(board);//build the index of where characters in the board are.
        List<position> startingPoints = index.get(word.charAt(0));//Find all possible starting point in the board.
        boolean[][] visited = new boolean[board.length][board[0].length];//Makes a table of place visited.
        
        if(startingPoints == null || startingPoints.size() == 0){return false;}
        
        for(position p : startingPoints){
            visited[p.row][p.col] = true;// mark the given position as seen
            if( exists(board, word, visited, p, 1)  ){return true;}
            visited[p.row][p.col] = false; // unmark the given position. We may need this character later.
        }
        return false;
    }
    
    // The wrapper function that does all real work.
    public boolean exists(char[][] board, String word, boolean[][] visited, position pos, int currLength){
        if(currLength == word.length()){return true;}
        
        List<position> nextMoves = validMoves(board, visited, pos, word.charAt(currLength));
        for(position move : nextMoves){
            if(!visited[move.row][move.col]){
               visited[move.row][move.col] = true;// mark the given position as seen
               if ( exists(board, word, visited, move, currLength + 1) ){return true;}
               visited[move.row][move.col] = false;// unmark the given position. We may need this character later.
            }
        }
        return false;
    }
    /*This function generates a maping from characters to their respective position in the board.
    * One could get better performance if instead of finding all the characters in the board if we find integrate this function into the 
    * main function and run the for loop when we encounter a desired character.
    */
    public HashMap<Character, List<position>> buildIndex(char[][] board){
        HashMap<Character,List<position>> index = new HashMap<Character, List<position>>();
        for(int i = 0; i != board.length; ++i){
            for(int j = 0; j!= board[0].length; ++j){
                if(index.containsKey(board[i][j])){
                    index.get(board[i][j]).add(new position(i,j));
                }
                else{
                    List<position> list = new ArrayList<position>();
                    list.add(new position(i,j));
                    index.put(board[i][j], list );
                }
            }
        }
        return index;
    }
    
    
    //This function returns a list of all vaild move from a given postion and the required characeter.
    public List<position> validMoves(char[][] board, boolean[][] visited, position currPos,char nextChar){
        List<position> moves = new ArrayList<position>();
        
        //Is the characeter below it admissible?
        if(currPos.row -1 >= 0 && nextChar == board[currPos.row - 1][currPos.col]){
            moves.add(new position(currPos.row - 1, currPos.col ));
        }
        //Is the characeter below it admissible?
        if(currPos.row + 1 < board.length  &&  nextChar == board[currPos.row + 1][currPos.col]){
            moves.add(new position(currPos.row + 1, currPos.col));
        }
        //Is the character to the left admissible?
        if(currPos.col - 1 >= 0 && nextChar == board[currPos.row][currPos.col - 1]){
            moves.add(new position(currPos.row, currPos.col - 1));
        }
        //Is the character to the right admissible?
        if(currPos.col + 1< board[0].length && nextChar == board[currPos.row][currPos.col + 1]){
            moves.add(new position(currPos.row, currPos.col + 1));
        }
        return moves;
    }
}
