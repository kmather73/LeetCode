class Solution {
public:
    int binaryGap(int N) {
        auto maxDist = 0;
        
        while(N)
        {
            auto x = N & (N-1);
            auto y = N - x;
            
            auto dist = 0;
            while(x && !(x&y))
            {
                y = (y << 1);
                ++dist;
            }
            maxDist = max(maxDist, dist);
            N = x;
        }
        
        return maxDist;
    }
};
