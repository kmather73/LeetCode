public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {

       int start = 0;
       int end = (matrix.length *  matrix[0].length) - 1;
       
       while(start <= end){
           int midPoint = (start + end ) / 2;
           int midPointValue = GetNumberInMatrixAt(matrix, midPoint);
           
           if(midPointValue == target){
               return true;
           }
           else if(midPointValue < target){
               start = midPoint + 1;
           }
           else{
               end = midPoint - 1;
           }
       }
       return false;
    }
    
    public int GetNumberInMatrixAt(int[][] matrix, int itemNumber){
        int rowNumber = itemNumber / matrix[0].length;
        int colNumber = itemNumber % matrix[0].length;

        return matrix[rowNumber][colNumber];
    }
}
