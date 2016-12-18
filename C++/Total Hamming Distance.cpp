class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int d = 0;
        vector<vector<int>> tbl(32/4, vector<int>(1+0xF));
        
        for(int i=0; i<nums.size(); ++i){
            for(int j=0; j < 32/4; ++j){
                ++tbl[j][0xF&(nums[i]>>(4*j))];
            }
        }
        
        for(int i=0; i < 32/4; ++i){
            for(int j=0; j <= 0xF; ++j){
                for(int k=j+1; k<=0xF; ++k){
                    d += tbl[i][j]*tbl[i][k] * __builtin_popcount(j^k);
                }
            }
        }
        return d;
    }
};
