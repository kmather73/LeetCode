class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        // find the max element then flip it to the top and then flip it to the bottom
        int size = A.size()-1;
        vector<int> flips;
        
        while(size)
        {
            int i = 0;
            for(int j=1; j <= size; ++j){
                if(A[i] < A[j]) i = j;
            }
            
            if(i != size)
            {
                flips.push_back(i+1);
                flips.push_back(size+1);
                
                for(int j=0; j <= i / 2; ++j) swap(A[j], A[i-j]);
                
                for(int j=0; j <= size/2; ++j) swap(A[j], A[size-j]);
            }
            
            --size;
        }
        
        return flips;
    }
};
