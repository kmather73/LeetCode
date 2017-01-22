class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size()% 2 == 0) return true;
        int n = nums.size();
        vector<vector<long>> dp(n, vector<long>(n, -1));
        int f= 0;
        long best = utill(nums, dp, 0, n-1, f);
        
        long a = 0;
        if(f) a = utill(nums, dp, 1,n-1, f); 
        else a = utill(nums, dp, 0, n-2, f);
        
        return best >= a;
    }
    
    long utill(vector<int>& v, vector<vector<long>> &dp, int i, int j, int& f){
        if(i > v.size() || i > j) return 0;
        if(i == j) return v[i];
        if(dp[i][j] != -1) return dp[i][j];
        
        int a = v[i] + min(utill(v,dp, i+1, j-1, f), utill(v, dp, i+2, j, f));
        int b = v[j] + min(utill(v,dp,i, j-2, f), utill(v,dp, i+1, j-1, f));
        dp[i][j] = max(a, b);
                        
        
        f = a > b;
        return dp[i][j];
    }
};
