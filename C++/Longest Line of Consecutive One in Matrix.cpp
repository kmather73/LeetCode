class Solution {
int dxx[4] = {1, 0, 1, 1};
int dyy[4] = {0, 1, 1, -1};

public:
    int longestLine(vector<vector<int>>& M) {
        if(M.size() == 0) return 0;
        int c = 0;
        int n = M.size();
        int m = M[0].size();
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                for(int k=0; k < 3; ++k){
                    if(M[i][j] ) c = max(c, visit(M, i, j, dxx[k], dyy[k], 0));
                }
                
                if(M[i][j] ) c = max(c, visit(M, i, j, dxx[3], dyy[3], 0));
            }    
        }
        return c;
    }
    
    int visit(vector<vector<int>> &M, int i, int j, int dx, int dy, int code){
        int n = M.size();
        int m = M[0].size();
        M[i][j] |= code;
        
        int c = 1;
        while(i+dx >= 0 && j+dy >= 0 && i+dx < n && j+dy < m && M[i+dx][j+dy]){
            i += dx;
            j += dy;
            ++c;
            M[i][j] |= code;
        }
        
        return c;
    }
};
