class Solution {
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
    
    public:
    int numEnclaves(vector<vector<int>>& A) {
        const int n = A.size();
        const int m = A[0].size();
        
        for(int i=0; i < n; ++i)
        {
            flood(A, i, 0);
            flood(A, i, m-1);
        }
        
        for(int j=1; j < m-1; ++j)
        {
            flood(A, 0, j);
            flood(A, n-1, j);
        }
        
        int count = 0;
        for(int i=1; i < n-1; ++i)
        {
            for(int j=1; j < m-1; ++j)
            {
                count += A[i][j];
            }
        }
        
        return count;
    }
    
    void flood(vector<vector<int>>& A, int i, int j)
    {
        int n = A.size();
        int m = A[0].size();
        if(!IsValidMove(i, j, n, m) || A[i][j] == 0) return;
        
        A[i][j] = 0;

        for(int k=0; k < 4; ++k)
        {
            auto x = i + dx[k];
            auto y = j + dy[k];
            flood(A, x, y);
        }
    }
    
    inline bool IsValidMove(int x, int y, int n, int m)
    {
        return x >= 0 && x < n &&
            y >= 0 && y < m;
    }
};
