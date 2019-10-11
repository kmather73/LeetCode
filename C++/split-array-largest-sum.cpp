class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long totalSum = 0;
        long maxEle = 0;
        for(auto x : nums) totalSum += x, maxEle = max(maxEle, (long)x);
        int n = nums.size();
        int left = maxEle;
        int right = min(totalSum, (long)INT_MAX);
        
        while(left < right)
        {
            long mid = (right - left) / 2 + left;
            auto partitions = 1;
            auto sum = 0L;
            for(long x : nums)
            {  
                if(sum + x > mid)
                {
                    sum = x;
                    ++partitions;
                }
                else
                {
                    sum += x;
                }
            }
            if(partitions >  m) left = mid + 1;
            else right = mid;
        }
        
        return right;
    }
};
