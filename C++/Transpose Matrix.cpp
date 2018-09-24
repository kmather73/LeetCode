class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        vector<vector<int>> M = vector<vector<int>>(m ,vector<int>(n));
        
        for(int i=0; i < n; ++i)
        {
            for(int j=0; j < m; ++j)
            {
                M[j][i] = A[i][j];
            }
        }
        return M;
    }
};
