class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        if(lower >= upper) return 0;
        
        int total = 0;
        int points = 0;
        
        --k;
        for(int i = 0; i < calories.size(); ++i)
        {
            total += calories[i];
            if(i >= k)
            {
                points = points + (total > upper) - (total < lower);
                total -= calories[i-k];
            }
        }
        
        return points;
    }
};
