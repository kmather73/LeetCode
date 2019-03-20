class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> counts(60);
        auto count = 0;
        for (auto it = time.rbegin(); it != time.rend(); ++it) 
        {
            count += counts[(60 - (*it%60))%60];
            ++counts[*it % 60];
        }
        
        return count;
    }
};
