class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> targets;
        vector<int> dp(366,-1);
        
        for(auto day : days) targets.insert(day);
        
        return Cost(*days.rbegin(), targets, costs, dp);
    }
    
    int Cost(int day, unordered_set<int>& days, vector<int>& costs, vector<int>& dp)
    {
        if(day <= 0) return 0;
        if(dp[day] != -1) return dp[day];
        if(!days.count(day))
        {
            return dp[day] = Cost(day-1, days, costs, dp);
        }
        
        
        auto oneDay = Cost(day - 1, days, costs, dp) + costs[0];
        auto sevenDays = Cost(day - 7,days, costs, dp) + costs[1];
        auto thirtyDays = Cost(day - 30, days, costs, dp) + costs[2];
        
        auto bestDeal = min(oneDay, min(sevenDays, thirtyDays));
        return dp[day] = bestDeal;
    }
};
