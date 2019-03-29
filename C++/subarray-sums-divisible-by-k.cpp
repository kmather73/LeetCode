class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int sum = 0;
        vector<int> mod(K);
        
        int subarrays = 0;
        for(int i=0; i < A.size(); ++i)
        {
            sum = ((sum + A[i]) % K + K) % K;
            ++mod[sum];
        }
        
        ++mod[0];
        for(auto x : mod)
        {
            subarrays += x * (x-1) / 2;
        }
        
        return subarrays;
    }
};
