public class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int length = triangle.size();
        int[] pathCost = new int[length];
        
        List<Integer> currentRow = triangle.get(length - 1);
        for(int i = 0; i < length; ++i){
            pathCost[i] = currentRow.get(i);
        }
        
        --length;
        
        while( length-- > 0 ){
            currentRow = triangle.get(length);
            int rowLength = currentRow.size();
            
            for(int i = 0; i < rowLength; ++i){
                pathCost[i] = currentRow.get(i) + Math.min(pathCost[i], pathCost[i+1]);
            }
        }
        
        return pathCost[0];
    }
}
