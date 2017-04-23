class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int m = nums.size();
        int n = m/2;
        
        long sum = 0;
        for(int i=0; i <m; i += 2){
            sum += nums[i];
        }
        
        return sum;
    }
};
