class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int n = A.size()/2;
        nth_element(A.begin(), A.begin() + n, A.begin()+ n + 1);
        nth_element(A.begin(), A.begin() + n - 1, A.begin() + n);
        nth_element(A.begin(), A.begin() + n - 2, A.begin() + n - 1);
        
        if(A[n-1] == A[n-2]) return A[n-1];
        
        return A[n];
    }
};
