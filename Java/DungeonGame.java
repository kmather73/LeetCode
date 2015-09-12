public class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
      if(dungeon == null || dungeon.length == 0){
          return 1;
      }
      
      int rows = dungeon.length - 1; 
      int cols = dungeon[0].length - 1;
      
      int[][] healthNeeded = new int[rows + 1][cols + 1];
      healthNeeded[rows][cols] = (dungeon[rows][cols] > 0? 0: -dungeon[rows][cols]) + 1; 
      
      //Fill the boundary values for the right wall
      for(int i = rows - 1; i >= 0; --i){
          healthNeeded[i][cols] =  healthNeeded[i+1][cols] - dungeon[i][cols];
          if(healthNeeded[i][cols] <= 0)
              healthNeeded[i][cols] = 1;
      }
      
      //Fill the boundary values for the bottom wall
      for(int j = cols-1; j >= 0; --j){
          healthNeeded[rows][j] = healthNeeded[rows][j+1] - dungeon[rows][j];
          if(healthNeeded[rows][j] <= 0)
              healthNeeded[rows][j] = 1;
      }
      
      //Traverse the dungeon.
      for(int i = rows-1; i >= 0; --i){
          for(int j = cols-1; j >= 0; --j){
              healthNeeded[i][j] = Math.min(healthNeeded[i][j + 1], healthNeeded[i+1][j]) - dungeon[i][j];
              if(healthNeeded[i][j] <= 0)
                  healthNeeded[i][j] = 1;
          }
      }
      return healthNeeded[0][0];
    }
}
