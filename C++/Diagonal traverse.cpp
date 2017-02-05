class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return {};
        vector<int> ele;
        int n = matrix.size();
        int m = matrix[0].size();
        
        int maxSum = n + m - 2;

        for (int sum = 0; sum <= maxSum; sum++) {
            if(sum%2 == 1){
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) {
                        if (i + j - sum == 0) {
                            ele.push_back(matrix[i][j]);
                        }
                    }
                }
            }
            
            else {
                for (int i = n-1; i >=0; --i) {
                    for (int j = m-1; j >= 0; --j) {
                        if (i + j - sum == 0) {
                            ele.push_back(matrix[i][j]);
                        }
                    }
                }
            }
        }
        
        return ele;
    }
};
