class Solution {
    unordered_set<int> primes;
public:
    Solution()
    {
        int p[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        for(auto x : p) primes.insert(x);
    }
    
    int countPrimeSetBits(int L, int R) 
    {
        auto count = 0;
        while(L <= R)
        {
            count += primes.count(__builtin_popcount(L));
            ++L;
        }
        
        return count;
    }
};
