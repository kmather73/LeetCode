class Solution {
public:
    int preimageSizeFZF(int K) {
        return BiSearch(K) - BiSearch(K-1);
    }
    
    long BiSearch(int K)
    {
        auto low = 0L;
        auto high = K*5L + 5L;
        
        while(high >= low)
        {
            auto mid = (high - low) / 2 + low;
            auto zeros = NumZeros(mid);
            if(zeros > K) high = mid - 1;
            else low = mid + 1;
        }
        
        return high;
    }
    
    int NumZeros(int x)
    {
        int count = 0;
        int div = 5;
        while(x)
        {
            count += (x / div);
            x = x / div;
        }
        return count;
    }
};
