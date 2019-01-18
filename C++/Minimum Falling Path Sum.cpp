class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int k = A[0].size()-1;
        for (int j=A.size()-2; j >= 0; --j)
        {
            for (int i=0; i < A[0].size(); ++i)
            {
                int m = A[j+1][i];
                
                if (i > 0) m = min(m, A[j+1][i-1]);
                if (i < k) m = min(m, A[j+1][i+1]);
                
                A[j][i] += m;
            }
        }
        
        int m = INT_MAX;
        for(int i=0; i < A.size(); ++i) m = min(m, A[0][i]);
        
        return m;
    }
};
