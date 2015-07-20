public class Solution {
    public int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];
        
        int nSquared = n*n;
        int count = 0;
        int index = 0;
        
        while(count < nSquared){
            int upper1 = matrix[0].length - index;
            
            for(int i = index; i < upper1; ++i)
                matrix[index][i] = ++count;
        
            int upper2 = matrix.length - index;
            int rightSide = matrix[0].length - 1 - index;
        
            for(int i = index + 1; i < upper2; ++i)
                matrix[i][rightSide] = ++count;
            
            int bottom = matrix.length - 1 - index;
        
            --upper1;
            if(bottom > index)
                while(--upper1 >= index)
                    matrix[bottom][upper1] = ++count;
        
            --upper2;
            if(rightSide > index)
                while(--upper2 > index)
                    matrix[upper2][index] = ++count;
            ++index;
        }
        return matrix;
    }
}
