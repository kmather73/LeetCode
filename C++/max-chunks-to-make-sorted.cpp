class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count = 0;
        int maxMissing = 0;
        int i = 0;
        int n = arr.size();        
        
        while(i != n)
        {
            ++count;
            do
            {
                maxMissing = max(maxMissing, arr[i]);
                ++i;
            } while(i <= maxMissing);
        }
        
        return count;
    }
};
