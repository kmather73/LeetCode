class Solution {
vector<int> Primes{0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
    
    public:
    int numPrimeArrangements(int n) 
    {
        int i = lower_bound(Primes.begin(), primes.end(), n); while(Primes[i+1] <= n) ++i;
        
        int j = n - i;
        long int total = 1;
        while(i)
        {
            total = (total * i) % 1000000007;
            --i;
        }
        
        while(j)
        {
            total = (total * j) % 1000000007;
            --j;
        }
        
        return (int) total;
    }
};
