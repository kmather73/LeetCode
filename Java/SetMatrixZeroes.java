

public class Solution {
    final int K_dummy = Integer.MAX_VALUE - 1 ;
    
    public void setZeroes(int[][] matrix) {
        for(int row = 0; row < matrix.length; ++row){
            boolean containsZero = false;
            
            for(int col = 0; col < matrix[0].length; ++ col){
                if(matrix[row][col] == 0){
                    containsZero = true;
                    floodColumn(matrix, row , col);
                }
                else if(matrix[row][col] == K_dummy){
                    matrix[row][col] = 0;
                    }
                }
            if(containsZero){
                floodRow(matrix, row);
            }
        }
    }
    
    public void floodRow(int[][] matrix, int row){
        for(int col = 0; col < matrix[0].length; ++ col){
            matrix[row][col] = 0;
        }
    }
    
    public void floodColumn(int[][] matrix, int row, int col){
        for(int i = 0; i <= row; ++i){
            matrix[i][col] = 0;
        }
        for(int i = row + 1; i < matrix.length; ++ i){
            if(matrix[i][col] != 0){
                matrix[i][col] = K_dummy;
            }
        } 
    }
}
