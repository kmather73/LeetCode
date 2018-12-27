class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int p = 0;
        int q = 1;
        int n = A.size();
        
        while(p < n && q < n)
        {
            while(p < n && !(A[p]%2)) p += 2;
            
            while(q < n && A[q]%2) q += 2;
            
            if(p < n && q < n) swap(A[p], A[q]);
        }
        
        return A;
    }
};
