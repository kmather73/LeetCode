class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = nums.size();
        int m = nums[0].size();
        
        if (r*c != n*m) return nums;
        
        vector<vector<int>> matrix = vector<vector<int>>(r, vector<int>(c));
        
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                int k = i*m + j;
                
                int rn = k / c;
                int cn = k % c;
                matrix[rn][cn] = nums[i][j];
            }
        }
        
        return matrix;
    }
};
