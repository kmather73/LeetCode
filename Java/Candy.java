public class Solution {
    public int candy(int[] ratings) {
        int length = ratings.length;
        int[] candysPerChild = new int[length];
        
        Arrays.fill(candysPerChild, 1);
        
        for(int i = 1; i < length; ++i)
            if(ratings[i] > ratings[i-1])
                candysPerChild[i] = candysPerChild[i-1] + 1;
        
        for(int i = length - 2; i >= 0; --i)
            if(ratings[i] > ratings[i+1])
                candysPerChild[i] = Math.max(candysPerChild[i],candysPerChild[i+1] + 1);
        
        int count = 0;
        for(int i = 0; i < length; ++i)
            count += candysPerChild[i];
        return count;
    }
}
