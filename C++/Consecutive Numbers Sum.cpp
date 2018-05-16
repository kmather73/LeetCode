class Solution {
public:
    int consecutiveNumbersSum(long long int N) {
        int count = 1;
        
        int limit = 1 + sqrt(2*N);
        
        for(int i=2; i < limit; ++i)
        {
            int diff = N - i*(i-1)/2;
            if(diff % i == 0) ++count;
        }
        
        
        return count;
    }
};
