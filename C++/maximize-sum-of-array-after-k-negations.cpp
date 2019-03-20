class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
         
        K = min(K, (int)A.size());
        for (auto i=0; K > 0 && A[i] < 0; ++i, --K) A[i] = -A[i];
        
        auto sum = 0;
        auto m = INT_MAX;
        for(auto x : A)
        {
            sum += x;
            m = min(m, x);
        }
        
        return sum - 2*(K%2) * m;
    }
};
