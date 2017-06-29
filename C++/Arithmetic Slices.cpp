class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int j=0;
        int count = 0;
        int n = A.size();
        while(j < n){
            int i = j;
            j += 2;
            while(j < n && A[i+1]-A[i] == A[j] - A[j-1]) ++j;
            
            int len = j-i;
            if(len >= 3){
                count += len*(len-1)/2 - len + 1;
            }
            --j;
        }
        
        return count;
    }
};
