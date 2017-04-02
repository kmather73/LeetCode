
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        vector<long> sums{nums[0]};
        unordered_map<long, vector<int>> jump;
        jump[nums[0]].push_back(0);
        
        for (int i=1; i < nums.size(); ++i) {
            sums.push_back( nums[i] + sums.back());
            jump[sums.back()].push_back(i);
        }
        
        for (int endIdx = nums.size() - 2; endIdx >= 4; --endIdx) {
            long endSum = sums.back() - sums[endIdx];
            
            for (int startIdx : jump[endSum]) {
                if (startIdx < endIdx) {
                    for (int j = startIdx + 1; j + 1 < endIdx; ++j) {
                        long secondSum = sums[j] - sums[startIdx+1];
                        long thridSum = sums[endIdx-1] - sums[j+1];
                        if (secondSum == thridSum && secondSum == endSum) return true;
                    }
                }
            }
        }
        
        return false;
    }
};
