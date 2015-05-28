public class Solution {
    public void rotate(int[][] matrix) {
        for(int row = 0; row < (matrix.length + 1) / 2; ++row){
            for(int col = 0; col < matrix[0].length / 2; ++col){
                rotateFourPixelsAt_A_Time(matrix, row, col);
            }
        }
        return;
    }
    public void rotateFourPixelsAt_A_Time(int[][] matrix, int row, int col){
        int newValue = matrix[row][col];
        
        for(int i = 0; i < 4; ++i){
            int nextRow = col;
            int nextCol = matrix.length - 1 - row;
            
            int oldValue = matrix[nextRow][nextCol];
            matrix[nextRow][nextCol] = newValue;
            newValue = oldValue;
            
            row = nextRow;
            col = nextCol;
        }
    }
}
