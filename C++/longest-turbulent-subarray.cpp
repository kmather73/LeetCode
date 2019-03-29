class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int n = A.size();
        int dp = 1;
        int best = 1;
        
        for(int i=1; i < n; ++i)
        {
            if (A[i] == A[i-1]) dp = 1; 
            else if(dp > 1 && 
                    ((A[i-2] > A[i-1] && A[i-1] < A[i]) ||
                    (A[i-2] < A[i-1] && A[i-1] > A[i])))
            
            {
                ++dp;
            }
            else dp = 2;
            
            best = max(best, dp);
        }
        
        return best;
    }
};
