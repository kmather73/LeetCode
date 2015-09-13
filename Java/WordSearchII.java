public class Solution {
    //simple class to represent where a position in a n*m board.
    public class position{
        int row;
        int col;
        position(){row = 0; col = 0;}
        position(int x, int y){row = x; col = y;}
    }
    
    public List<String> findWords(char[][] board, String[] words) {
        List<String> validWords = new ArrayList<String>();
        if(board == null || words == null || words.length == 0){
            return validWords;
        }
        
        HashMap<Character, List<position>> index = buildIndex(board);//build the index of where characters in the board are.
        boolean[][] visited = new boolean[board.length][board[0].length];//Makes a table of place visited.
        Set<String> validWordSet = new HashSet<String>();//Since we don't want duplicated words will store in set first.
        
        for(String word : words) //Checks which words are in the board.
            if( exist(board, word, visited, index) )
                validWordSet.add(word);
        
        return new ArrayList<String>(validWordSet);//convert the set to a list.
    }
    
    /* This function finds if a given word is in the grid. Here we process words from there last to first characters for better 
    * performace due to a heuristic of how english words are formed.
    */
    public boolean exist(char[][] board, String word, boolean[][] visited, HashMap<Character, List<position>> index) {
        if(word == null || word == "")
            return true;
        
        //Find all possible starting point in the board for the given word.
        List<position> startingPoints = index.get( word.charAt( word.length() - 1 ) );
        
        if(startingPoints == null || startingPoints.size() == 0)
            return false; //The last character is not on the board.
        
        for(position pos : startingPoints){
            visited[pos.row][pos.col] = true; // mark the given position as seen.
            if( existsUtill(board, word, visited, pos, word.length() - 2) ){
                visited[pos.row][pos.col] = false; // unmark the given position. We may need this for another word.
                return true;
            }
            visited[pos.row][pos.col] = false; // unmark the given position. We may need this character later.
        }
        return false;//faild to find the given word.
    }
    
    /* The wrapper function that does all real work to see if a given letter is adjacent to a given stating position.
       This function starts to check words from there last character to there first character. */
    public boolean existsUtill(char[][] board, String word, boolean[][] visited, position pos, int currLength){
        if(currLength == - 1) //base case there are no more characters let in the given word to check.
            return true; 
        
        List<position> nextMoves = validMoves(board, visited, pos, word.charAt(currLength)); 
        for(position move : nextMoves){
            if(!visited[move.row][move.col]){
               visited[move.row][move.col] = true; // mark the given position as seen.
               if ( existsUtill(board, word, visited, move, currLength - 1) ){
                   visited[move.row][move.col] = false; //Need to unmark this character, maybe needed for another word.
                   return true;
               }
               visited[move.row][move.col] = false; // Unmark the given character, maybe needed later.
            }
        }
        return false;//faild to find the given word. 
    }
    
    //This function generates a maping from characters to their respective position in the board.
    public HashMap<Character, List<position>> buildIndex(char[][] board){
        HashMap<Character,List<position>> index = new HashMap<Character, List<position>>();
        
        for(int i = 0; i != board.length; ++i){
            for(int j = 0; j != board[0].length; ++j){
                if( index.containsKey( board[i][j] ) ) // Have encountered this character before so add the position to the list.
                    index.get(board[i][j]).add(new position(i,j));
                    
                else{// Have not encountered this character before.
                    List<position> list = new ArrayList<position>();
                    list.add(new position(i, j) );
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
        if(currPos.row -1 >= 0 && nextChar == board[currPos.row - 1][currPos.col])
            moves.add(new position(currPos.row - 1, currPos.col ));
        
        //Is the characeter below it admissible?
        if(currPos.row + 1 < board.length  &&  nextChar == board[currPos.row + 1][currPos.col])
            moves.add(new position(currPos.row + 1, currPos.col));
        
        //Is the character to the left admissible?
        if(currPos.col - 1 >= 0 && nextChar == board[currPos.row][currPos.col - 1])
            moves.add(new position(currPos.row, currPos.col - 1));
            
        //Is the character to the right admissible?
        if(currPos.col + 1 < board[0].length && nextChar == board[currPos.row][currPos.col + 1])
            moves.add(new position(currPos.row, currPos.col + 1));
        
        return moves;
    }
}
