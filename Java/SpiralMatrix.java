public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        ArrayList<Integer> myList = new ArrayList<Integer>();
        if(matrix.length == 0 || matrix == null)
            return myList;
        int upperBound = (1 + Math.min(matrix.length, matrix[0].length)) >> 1;
        
        for(int i = 0; i < upperBound ; ++i)
            getShell(matrix, i, myList);
        return myList;
    }
    
    public void getShell(int[][] matrix, int index, List<Integer> myList){
        int upper1 = matrix[0].length - index;
        
        for(int i = index; i < upper1; ++i)
            myList.add(matrix[index][i]);
        
        int upper2 = matrix.length - index;
        int rightSide = matrix[0].length - 1 - index;
        
        for(int i = index + 1; i < upper2; ++i)
            myList.add(matrix[i][rightSide]);
            
        int bottom = matrix.length - 1 - index;
        
        --upper1;
        if(bottom > index)
            while(--upper1 >= index)
                myList.add(matrix[bottom][upper1]);
        
        --upper2;
        if(rightSide > index)
            while(--upper2 > index)
                myList.add(matrix[upper2][index]);
    }   
}
