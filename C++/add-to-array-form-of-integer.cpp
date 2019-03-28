class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int i= A.size() - 1;
        while(K && i >= 0)
        {
            K = (K + A[i]);
            A[i--] = K % 10;
            K /= 10;
        }
        
        if(i < 0) 
        {
            vector<int> B;
            while(K)
            {
                B.push_back(K%10);
                K /= 10;
            }
            reverse(B.begin(), B.end());
            B.insert(B.end(), A.begin(), A.end());
            swap(A, B);
        }
        
        return A;
    }
};
