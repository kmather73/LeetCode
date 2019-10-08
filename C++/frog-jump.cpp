class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,  unordered_map<int, bool>> dp;
        unordered_set<int> stoneSet;
        for(auto stone : stones) stoneSet.insert(stone);
        
        return RunDP(0, stones.back(), 0, dp, stoneSet);
    }
    
    bool RunDP(int start, int target, int k, unordered_map<int,  unordered_map<int, bool>> &dp, unordered_set<int> &stones)
    {
        if(!stones.count(start)) return false;
        if(dp.count(start) && dp[start].count(k)) return dp[start][k];
        
        bool nextStep = abs(target - (start + k)) < 2;
        
        if(!nextStep)
        {
            for(int d = max(1, k-1); !nextStep && d < k+2; ++d)
            {
                int nextMove = start + d;
                if(stones.count(nextMove))
                {
                    nextStep = RunDP(nextMove, target, d, dp, stones);
                }
            }
        }
        
        return dp[start][k] = nextStep;
    }
};
