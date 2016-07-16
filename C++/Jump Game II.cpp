class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() <= 1) return 0;
        int steps = 0; int maxDist = 0; int nextDist=0;
        
        for(int i=0; i < n; ++i) {
            if(i > maxDist){
                maxDist = nextDist;
                ++steps;
            }
            nextDist = max(nextDist, i+nums[i]);
        }
        return steps;
    }
};
