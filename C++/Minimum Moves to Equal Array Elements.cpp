class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves = 0;
        sort(nums.begin(), nums.end());
        
        for(int x: nums){
            moves += x - nums[0];
        }
        
        return moves;
    }
};
