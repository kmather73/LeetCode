class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int i=0; i < A.size(); ++i) {
            int m = A[i].size();
            for(int j=0; 2*j+1 < A[i].size(); ++j) swap(A[i][j], A[i][m-j-1]);
            for(int j=0; j < A[i].size(); ++j) A[i][j] = !A[i][j];
        }
        
        return A;
    }
};
