class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> row_mins(m, INT_MAX);
        vector<int> col_maxs(n, INT_MIN);
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                row_mins[i] = min(row_mins[i], matrix[i][j]);
                col_maxs[j] = max(col_maxs[j], matrix[i][j]);
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(col_maxs[j] == row_mins[i]) {
                    ans.push_back(col_maxs[j]);
                }
            }
        }
        
        return ans;
    }
};
