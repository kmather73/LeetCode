class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size()) return false;
        
        int i = 0, n = A.size();
        bool HasSame = false;
        int swaps = 0;
        unordered_map<char,int> c;
        
        while(i < n && A[i] == B[i])
        {
            ++c[A[i]];
            HasSame = HasSame || c[A[i]] > 1;
            ++i;
        }
        
        if(i == n) return HasSame;

        int j = i+1;
        while(j < n && A[j] == B[j]) ++j;
        
        if(j == n) return false;
        
        swap(A[i], A[j]);
        return A == B;
    }
};
