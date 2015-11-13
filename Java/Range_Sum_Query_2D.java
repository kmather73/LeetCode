public class NumMatrix {
    int[][] leftCornerSums;
    
    public NumMatrix(int[][] matrix) {
        if(matrix.length == 0)
            leftCornerSums = new int[2][2];
        else
        {
            leftCornerSums = new int[matrix.length+1][matrix[0].length+1];
            for(int i = 0; i < matrix.length; ++i){
                int currRowSum = 0;
                for(int j = 0; j < matrix[0].length; ++j){
                    currRowSum += matrix[i][j];
                    leftCornerSums[i+1][j+1] = leftCornerSums[i][j+1] + currRowSum;
                }
            }
        }
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        
        return leftCornerSums[row2+1][col2+1] + leftCornerSums[row1][col1] 
                -leftCornerSums[row2+1][col1] - leftCornerSums[row1][col2+1];
    }
}
