class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {       
        vector<int> A, B;
        for(int i = 0; i < arr1.size(); ++i)
        {
            A.push_back(arr1[i] + arr2[i]);
            B.push_back(arr1[i] - arr2[i]);
        }
        
        auto mmm = 0;
        auto maxA = 0;
        auto maxB = 0;
        auto minA = 0, minB = 0;
        for(int i = 0; i < arr1.size(); ++i)
        {
            if(A[i] > A[maxA]) maxA = i;
            if(A[i] < A[minA]) minA = i;
            if(B[i] > B[maxB]) maxB = i;
            if(B[i] < B[minB]) minB = i;
            
            mmm = max(mmm, i - maxA + A[maxA] - A[i]);
            mmm = max(mmm, i - minA + A[i] - A[minA]);
            mmm = max(mmm, i - maxB + B[maxB] - B[i]);
            mmm = max(mmm, i - minB + B[i] - B[minB]);
        }
        
        return mmm;
    }
};
