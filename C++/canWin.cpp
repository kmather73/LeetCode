class Solution {
    unordered_map<int,bool> dp;
    int tbl[20]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    
    public:
    bool canIWin(int maxInt, int dt) {
        if(maxInt*(maxInt+1) < 2*dt) return false;
        
        int canUse = (1<<maxInt)-1;
        int sum = 0;
        return canWin(0, dt, canUse, sum);
    }
    
    bool canWin(int used, int& dt, int& canUse, int& sum){
        if(dp.count(used) > 0) return dp[used];
        
        int j = used ^ canUse;
        while(j){
            int b = j&(~(j&(j-1)));
            j = j&(j-1);

            sum += tbl[(int)log2(b)];
            dp[used] = sum >= dt || !canWin(used|b, dt, canUse, sum);
            sum -= tbl[(int)log2(b)];

            if( dp[used] )  return dp[used];
        }
        return false;
    }
};
