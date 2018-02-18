class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        bool isToep = true;
        
        for(int i=0; i < n; ++i)
        {
            int r = i+1;
            int c = 0+1;
            
            while(r < n && c < m)
            {
                isToep = isToep && matrix[r-1][c-1] == matrix[r][c];
                ++c;
                ++r;
            }
        }
        
        for(int i=1; i < m; ++i)
        {
            int r = 0+1;
            int c = i+1;
            while(r < n && c < m)
            {
                isToep = isToep && matrix[r-1][c-1] == matrix[r][c];
                ++c;
                ++r;
            }
        }
        
        return isToep;
    }
};
