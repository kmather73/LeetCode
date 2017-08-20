class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int n = M.size(), m = M[0].size();
        
        vector<vector<int>> MS = vector<vector<int>>(n, vector<int>(m));
        
        vector<int> dx  {0, 1, -1, 0,  0, 1,  1, -1, -1};
        vector<int> dy  {0, 0,  0, 1, -1, 1, -1, 1, -1};
        
        for(int i=0; i < n; ++i) {
            for(int j=0; j < m; ++j){
                int count = 0;
                double sum = 0.0;
                for(int k=0 ; k<dx.size(); ++k){
                    
                    if(i+dx[k] >= 0 && i+dx[k] < n && j+dy[k] >= 0 && j+dy[k] < m){
                        sum += M[i+dx[k]][j+dy[k]];
                        ++count;
                    }
                    
                }
                
                MS[i][j] = sum/count;
            }
        }
        
        return MS;
    }
};
