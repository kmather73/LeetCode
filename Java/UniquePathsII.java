/*DP, did a bottom up approach by setting up the boundary conditions so that the lower right corner value will be 1. 
* Then let the information percolate up to the upper left corner.
*/
public class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if(obstacleGrid == null || obstacleGrid.length == 0){return 0;}
        
        int[][] counts = new int[obstacleGrid.length + 1 ][obstacleGrid[0].length + 1];//Each cell keeps track of how many paths there are from that point to the lower right corner
        counts[obstacleGrid.length][obstacleGrid[0].length - 1] = 1;// set up the boundery conditions for this DP.
        
        for(int i = obstacleGrid.length - 1; i >= 0; --i){//Let the information percolate.
            for(int j = obstacleGrid[0].length -1; j >= 0; --j){
                if(obstacleGrid[i][j] == 1){//If the cell has an obstacle then we cant reach it, so let it to zero.
                    counts[i][j] = 0;
                }
                else{
                    counts[i][j] = counts[i+1][j] + counts[i][j+1];
                }
            }
        }
        return counts[0][0];
    }
}
