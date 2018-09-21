class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        return IsMono(A, 1) || IsMono(A, -1);
    }
    
    bool IsMono(vector<int> &A, int mult)
    {
        bool mono = true;
        for(int i=1; i<A.size() && mono; ++i)
        {
            mono = A[i-1]*mult <= A[i]*mult;
        }
        return mono;
    }
};
