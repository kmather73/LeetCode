class Solution {
public:
    bool splitArray(vector<int>& nums) {
        unordered_map<long, vector<int>> jump;
        jump[nums[0]].push_back(0);
        
        for (int i=1; i < nums.size(); ++i) {
            nums[i] += nums[i-1]; 
            jump[nums[i]].push_back(i);
        }
        
        for (int endIdx = nums.size() - 2; endIdx >= 4; --endIdx) {
            long endSum = nums.back() - nums[endIdx];
    
            for (int startIdx: jump[endSum]) {
                for (int j = startIdx + 1; j+1 < endIdx; ++j) {
                    long secondSum = nums[j] - nums[startIdx+1];
                    long thridSum = nums[endIdx-1] - nums[j+1];
                        
                    if (secondSum == thridSum && secondSum == endSum) return true;
                }
            }
        }
        
        return false;
    }
};
