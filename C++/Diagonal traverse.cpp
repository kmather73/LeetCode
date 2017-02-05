class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return {};
        vector<int> ele;
        int n = matrix.size();
        int m = matrix[0].size();
        int maxSum = n + m - 2;

        for (int sum = 0; sum <= maxSum; ++sum) {
            int delta = 1 - 2*(sum%2 == 0);
            int iStart = (n-1) * (sum%2 == 0);
            int jStart = (m-1) * (sum%2 == 0);
            
            for (int i = iStart; i >= 0 && i < n; i += delta) {
                for (int j = jStart; j>= 0 && j < m; j += delta) {
                    if (i + j - sum == 0) {
                        ele.push_back(matrix[i][j]);
                    }
                }
            }
        }
        return ele;
    }
};
