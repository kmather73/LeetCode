public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        int sum[] = {-1,-1};
        
        for(int i=0 ; i<numbers.length ; i++){
            if(map.containsKey(numbers[i])){
                sum[0] = map.get(numbers[i])+1;
                sum[1] = i+1;
                return sum;
            }
            map.put(target - numbers[i],i);
        }
        return sum;
    }
}
