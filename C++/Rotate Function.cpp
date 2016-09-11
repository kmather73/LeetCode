class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        size_t n = A.size();
        long long int tSum = 0;
        for(int x : A) tSum += x;
        
        long long int sum = 0;
        for (size_t i=0; i < A.size(); ++i) sum += i*A[i];
        
        long long int max = sum;
        
        for(size_t i=1; i < A.size(); ++i){
            sum += tSum - n*A[n-i];
            max = std::max(max, sum);
        }
        
        return max;
    }
};
