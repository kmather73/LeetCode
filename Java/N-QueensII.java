//Now only uses O(n) memory instead of O(n^2) memory. Made the mechanism to test if a position in open much simpler.

public class Solution {
    public int totalNQueens(int size) {
        Board myQueens = new Board(size);
        solveQueenUtill(myQueens, 0);
        return myQueens.numberOfpossibleMoves();
    }
    public void solveQueenUtill(Board myBoard, int colNum){
        if(colNum >= myBoard.size()){//Base case, no more columns left to place a queen.
            return;
        }
        for(int row = 0; row < myBoard.size(); ++row){
            if(myBoard.validMove(row, colNum)){
                myBoard.placeQueenAt(row, colNum);
                solveQueenUtill(myBoard, colNum + 1);
                myBoard.removeQueenAt(row, colNum);
            }
        }
        return;
    }
    
    public class Board{
        private int sizeOfBoard;
        private boolean[] attackLeftDiag;
        private boolean[] attackRightDiag;
        private int numberOfQueensPlaced;
        private int numberOfValidConfigOfQueens;
        
        public Board(int n){
            attackLeftDiag = new boolean[2*n - 1];
            attackRightDiag = new boolean[2*n - 1];
            attackSide = new boolean[n];
            
            numberOfQueensPlaced = 0;
            numberOfValidConfigOfQueens = 0;
            sizeOfBoard = n;
        }
        
        public boolean validMove(int row, int col){
            int left = row + col;
            int right = sizeOfBoard - 1  - row + col;
            
            return !attackRightDiag[right] && !attackLeftDiag[left] && !attackSide[row];
        }
        
        public void placeQueenAt(int row, int col){
            numberOfQueensPlaced++;
            
            attackSide[row] = true;
            
            int left = row + col;
            attackLeftDiag[left] = true;
            
            int right = sizeOfBoard - 1  - row + col;
            attackRightDiag[right] = true;
            
            if(numberOfQueensPlaced == sizeOfBoard){
                addConfigToCount();
            }
        }
        
        public void removeQueenAt(int row, int col){
            --numberOfQueensPlaced;
            
            attackSide[row] = false;
            
            int left = row + col;
            attackLeftDiag[left] = false;
            
            int right = sizeOfBoard - 1  - row + col;
            attackRightDiag[right] = false;
        }
        
        private void addConfigToCount(){
            ++numberOfValidConfigOfQueens;
        }
        public int numberOfpossibleMoves(){
            return numberOfValidConfigOfQueens;
        }
        public int size(){
            return sizeOfBoard;
        }
    }
}




//Old Version, was able to make it better in many ways.
public class Solution {
    public class Board{
        private int sizeOfBoard;
        private boolean[][] openPositions;
        private int[] rowUsedByColNumber;
        private int[] colUsedByRowNumber;
        private int numberOfQueensPlaced;
        private int numberOfValidConfigOfQueens;
        
        public Board(int n){
            openPositions = new boolean[n][n];//Table of positions of that are under attack by some queen.
            numberOfQueensPlaced = 0;
            rowUsedByColNumber = new int[n];
            numberOfValidConfigOfQueens = 0;
            sizeOfBoard = n;
        }
        public boolean validMove(int row, int col){
            return !openPositions[row][col];
        }
        
        public void placeQueenAt(int row, int col){
            numberOfQueensPlaced++;
            rowUsedByColNumber[col] = row + 1;
            
            markRow(row, col);//Only need to propagate information to the right. No need for markCol.
            markDiagonal(row, col);
            
            if(numberOfQueensPlaced == sizeOfBoard){
                addConfigToCount();
            }
        }
        public void removeQueenAt(int row, int col){
            --numberOfQueensPlaced;
            rowUsedByColNumber[col] = 0;
            
            unMarkRow(row, col);
            unMarkDiagonal(row, col);
        }
        private void markRow(int row, int col){
            for(int i = col + 1; i < sizeOfBoard; ++i){
                openPositions[row][i] = true;
            }
        }
        private void unMarkRow(int row, int col){
            for(int i = col + 1; i < sizeOfBoard; ++i){
                openPositions[row][i] = false;
            }
        }
        private void markDiagonal(int row, int col){
            markUpperDiagonal(row, col);
            markLowerDiagonal(row, col);
        }
        private void markUpperDiagonal(int row, int col){
            while(row >= 0 && col < sizeOfBoard){
                openPositions[row][col] = true;
                --row;
                ++col;
            }
        }
        private void markLowerDiagonal(int row, int col){
            while(row < sizeOfBoard && col < sizeOfBoard){
                openPositions[row][col] = true;
                ++row;
                ++col;
            }
        }
        private void unMarkDiagonal(int row, int col){
            unMarkUpperDiagonal(row, col);
            unMarkLowerDiagonal(row, col);
            reMark(row, col);
        }
        private void unMarkUpperDiagonal(int row, int col){
            while(row >= 0 && col < sizeOfBoard){
                openPositions[row][col] = false;
                --row;
                ++col;
            }
        }
        private void unMarkLowerDiagonal(int row, int col){
            while(row < sizeOfBoard && col < sizeOfBoard){
                openPositions[row][col] = false;
                ++row;
                ++col;
            }
        }
        //Remark the positions on the board that the other queens on the board can attack that were removed when we unmarked the row and diagonal of the queen removed.
        private void reMark(int row, int col){
            for(int i = 0; i < sizeOfBoard; ++i){
                int rowOfOtherCol = rowUsedByColNumber[i] - 1;
                if(rowOfOtherCol != -1){//Is there a queen in this row?
                    int colOffSet = Math.abs(rowOfOtherCol - row);
                    int rowOffSet = col - i;
                    
                    if(col + colOffSet < sizeOfBoard){
                        openPositions[rowOfOtherCol][col + colOffSet] = true;//Mark the one open square in the row of other queen.
                    }
                    if(i+ colOffSet < sizeOfBoard){
                        openPositions[row][i + colOffSet] = true;//Mark the diagonal of the other queen at can attack in the row that the removed queen was in.
                    }
                    //remake were a queen and the queen removed could both attack in the diagonal direction.
                    int colD = (i + col + row - rowOfOtherCol) / 2;//First intersection point.
                    int rowD = (col - i + row + rowOfOtherCol) / 2;//First intersection point.
                    
                    if(colD >= 0 && colD < sizeOfBoard && rowD >= 0 && rowD < sizeOfBoard){//Does that point lie in the board?
                        if( colD*2 == i + col + row - rowOfOtherCol && rowD*2 == col - i + row + rowOfOtherCol && colD >col){//Is the point a lattice point?
                            openPositions[rowD][colD] = true;
                        }
                    }
                    
                    colD = (i + col - row + rowOfOtherCol) / 2;//Second intersection point.
                    rowD = (i - col  +row + rowOfOtherCol) / 2;//Second intersection point.
                    if(colD >= 0 && colD < sizeOfBoard && rowD >= 0 && rowD < sizeOfBoard){
                        if(colD*2 == i + col - row + rowOfOtherCol && rowD*2 == i - col  +row + rowOfOtherCol && colD > col ){//Is the point a lattice point?
                            openPositions[rowD][colD] = true;
                        }
                    }
                }
            }
        }
        private void addConfigToCount(){
            ++numberOfValidConfigOfQueens;
        }
        public int numberOfpossibleMoves(){
            return numberOfValidConfigOfQueens;
        }
        public int size(){
            return sizeOfBoard;
        }
    }

    public int totalNQueens(int size) {
        Board myQueens = new Board(size);
        solveQueenUtill(myQueens, 0);
        return myQueens.numberOfpossibleMoves();
    }
    
    public void solveQueenUtill(Board myBoard, int colNum){
        if(colNum >= myBoard.size()){//Base case, no more columns left to place a queen.
            return;
        }
        for(int row = 0; row < myBoard.size(); ++row){
            if(myBoard.validMove(row, colNum)){
                myBoard.placeQueenAt(row, colNum);
                solveQueenUtill(myBoard, colNum + 1);
                myBoard.removeQueenAt(row, colNum);
            }
        }
        return;
    }
}
