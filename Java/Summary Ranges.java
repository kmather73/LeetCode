public class Solution {
    public List<String> summaryRanges(int[] nums) {
       ArrayList<String> range = new ArrayList<String>();
       
       if(nums.length == 0)
          return range;

       int start = nums[0];
       int end = nums[0];
       
       for(int i = 1; i < nums.length; ++i){
            if(nums[i] == nums[i-1] + 1)
                ++end;
            else{
                if(start == end)
                    range.add("" + start);
                else 
                    range.add("" + start + "->" + end);
                start = nums[i];
                end = nums[i];
            }
       }
       if(end == start) 
            range.add("" + start); 
       else 
            range.add("" + start +"->" + end);
       return range;
    }
}
