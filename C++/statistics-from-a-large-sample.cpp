class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int Min = 255, Max = 0;
        long int sum = 0, size = 0;
        int mode = 0, modeCount = 0;
        
        for(int i = 0; i < count.size(); ++i)
        {
            if(count[i])
            {
                Min = min(Min, i);
                Max = max(Max, i);
                sum += i * count[i];
                size += count[i];
                
                if(count[i] > modeCount) mode = i, modeCount = count[i];
            }
            
            count[i] += i > 0 ? count[i-1] : 0;
        }
        
        auto itLow = lower_bound(count.begin(), count.end(), (size+1)/2) - count.begin();
        auto itHi = lower_bound(count.begin(), count.end(), (size+2)/2) - count.begin();
        
        return {
            (double)Min,
            (double)Max,
            (double)sum / size,
            (double) (itLow + itHi) / 2.0,
            (double) mode
            };
    }
};
