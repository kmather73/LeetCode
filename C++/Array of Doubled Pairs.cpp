class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        sort(A.begin(), A.end(), [](const int& A, const int& B)
             {
                 return abs(A) < abs(B);
             });
        
        unordered_map<int, int> counts;
        
        for(int i=0; i < A.size(); ++i) ++counts[A[i]];
        
        for(int i=0; i < A.size(); ++i)
        {
            if(counts[A[i]] > 0)
            {
                --counts[A[i]];
                if(counts[2*A[i]] == 0) return false; 
                --counts[2*A[i]];
            }
        }
        
        for(auto x : counts) if(x.second != 0) return false;
        
        return true;
    }
};
