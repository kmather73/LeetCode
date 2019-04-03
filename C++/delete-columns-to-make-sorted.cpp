class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int d = 0;
        int n = A[0].size();
        int m = A.size();
        
        for(int i=0; i < n; ++i)
        {
            int j=0;
            for(j=1; j < m; ++j)
            {
                if(A[j][i] < A[j-1][i]) break;
            }
            
            d += (j < m); 
        }
        
        return d;
    }
};
