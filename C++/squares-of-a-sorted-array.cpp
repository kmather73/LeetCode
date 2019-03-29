class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> squares;
        int i = 0, j = A.size()-1;
        while(i <= j)
        {
            auto ai2 = A[i] * A[i];
            auto aj2 = A[j] * A[j];
            if(ai2 > aj2)
            {
                squares.push_back(ai2);
                ++i;
            }
            else
            {
                squares.push_back(aj2);
                --j;
            }
        }
        reverse(squares.begin(), squares.end());
        return squares;
    }
};
