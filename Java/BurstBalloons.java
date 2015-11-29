public class Solution {
    public int maxCoins(int[] nums) {
        if(nums.length == 0 )
            return 0;
        if(nums.length == 1)
            return nums[0];

        ArrayList<Integer> sameNums = new ArrayList<Integer>(nums.length);
        sameNums.add(1);
        for(int i = 0; i < nums.length; ++i){
            //if(nums[i] != 0)
                sameNums.add(nums[i]);
        }
        sameNums.add(1);
        return maxCoins3(sameNums);
    }

//DP O(n^3)
    public int maxCoins3(ArrayList<Integer> nums){
        int coins[][] = new int[nums.size()][nums.size()];
        int maxLength = nums.size()-2;
        int mostCoins = 0;
        
        for(int length = 1; length <= maxLength; ++length){
            for(int start = 1; start <= maxLength - length + 1; ++start){
                int end = length + start - 1;
                
                mostCoins = 0;
                for(int popLast = start; popLast <= end; ++popLast){
                    int popedCoins = coins[start][popLast-1] + nums.get(start-1) * nums.get(popLast) * nums.get(end+1)
                                        + coins[popLast+1][end];
                    
                    if(popedCoins > mostCoins)
                        mostCoins = popedCoins;
                }
                coins[start][end] = mostCoins;
            }
        }
        return mostCoins;
    }
    
    //This approach gives TLE.
    public int maxCoins(List<Integer> nums, HashMap<List<Integer>, Integer> map){
        int max = 0;
        if(nums.size() == 2){
            max = nums.get(0)*nums.get(1) + Math.max(nums.get(0), nums.get(1));
            map.put(nums, max);
        }
        else if(map.containsKey(nums))
            max = map.get(nums);
        else{
            int temp = nums.remove(0);
            max = temp*nums.get(0) + maxCoins(nums,map);
            nums.add(0,temp);
            
            int limit = nums.size()-1;
            for(int i = 1; i < limit; ++i){
                temp = nums.remove(i);
                max = Math.max(max, nums.get(i-1)*temp*nums.get(i) + maxCoins(nums,map));
                nums.add(i,temp);
            }
            
            temp = nums.remove(limit);
            max = Math.max(max, temp*nums.get(limit-1) + maxCoins(nums,map));
            nums.add(temp);
            
            map.put(nums,max);
        }
        return max;
    }
}
