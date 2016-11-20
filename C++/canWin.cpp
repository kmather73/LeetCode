class Solution {
    unordered_map<int,bool> dp;
    unordered_map<int,int> sum;
    int tbl[21]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    
    public:
    bool canIWin(int maxInt, int dt) {
        if(maxInt*(maxInt+1) < 2*dt) return false;
        
        int canUse = (1<<maxInt)-1;
        return canWin(0, dt, canUse);
    }
    
    bool canWin(int used, int& dt, int& canUse){
        if(dp.count(used) > 0) return dp[used];
        
        int j = used ^ canUse;
        while(j){
            int b = j&(~(j&(j-1)));
            j = j&(j-1);
            sum[used | b] = sum[used] + tbl[(int)log2(b)];
            
            dp[used] = sum[used|b] >= dt || !canWin(used|b, dt, canUse);
            if( dp[used] )  return dp[used];
        }
        return false;
    }
};
