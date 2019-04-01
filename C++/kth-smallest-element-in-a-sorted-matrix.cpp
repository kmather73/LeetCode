class Solution {
public:
    int kthSmallest(const vector<vector<int>>& matrix, const int k)
    {
        int left = matrix[0][0];
        int right = matrix.back().back();
        
        while(left < right)
        {
            auto mid = (right - left) / 2 + left;
            int less = NumberOfElementsLessThan(matrix, mid);
            if(less < k) left = mid + 1;
            else right = mid;
        }
        
        return left;
    }
    
    inline int NumberOfElementsLessThan(const vector<vector<int>>& matrix, int x)
    {
        int n = matrix.size();
        auto i = n-1, j = 0;
        auto num = 0;
        while(i >= 0 && j < n)
        {
            if(matrix[i][j] > x) --i;
            else
            {
                num += i + 1;
                ++j;
            }
        }    
        return num;
    }  
};
