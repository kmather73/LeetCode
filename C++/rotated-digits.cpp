class Solution {
public:
    int rotatedDigits(int N) {
        vector<int> good {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};
                
        int count = 0;
        for(int i=1; i <= N; ++i)
        {
            auto n = i;
            int rot = 0, offset = 1;
            while(n)
            {
                int r = n % 10;
                if(good[r] == -1)
                {
                    break;
                }
                
                rot = rot + good[r] * offset;
                n = n / 10;
                offset *= 10;
            }
            
            count += (!n) && (i != rot);
        }
        
        return count;
    }
};
