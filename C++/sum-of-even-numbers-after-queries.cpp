class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        auto sum = 0;
        for(auto x : A) if (x%2 == 0) sum += x;
        
        vector<int> results;
        for(auto q : queries)
        {
            if(A[q[1]] % 2 == 0) sum -= A[q[1]];
            A[q[1]] += q[0];
            if(A[q[1]] % 2 == 0) sum += A[q[1]];
            
            results.push_back(sum);
        }
        
        return results;
    }
};
