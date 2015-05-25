public class Solution {
    public int maxArea(int[] height) {
        if(height.length < 2){//Edge case, can't form a cell.
            return 0;
        }
        
        int leftPosition = 0;
        int rightPosition = height.length - 1;
        
        int mostWaterSeen = 0;
        while(leftPosition < rightPosition){
            mostWaterSeen = Math.max(mostWaterSeen, (rightPosition - leftPosition)*Math.min(height[leftPosition], height[rightPosition]));
            
            if(height[leftPosition] < height[rightPosition]){
                leftPosition++;
            }
            else{
                rightPosition--;
            }
        }
        return mostWaterSeen;
    }
}
