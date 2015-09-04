public class Solution {
    public int hIndex(int[] citations) {
        int n = citations.length;
        int i = 0;
            
        while(i < n &&  citations[i] < n - i)
            ++i;
        
        return n - i;
    }
}
