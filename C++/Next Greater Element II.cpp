class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> gtr;
        for(int i=0; i<nums.size(); ++i){
            int end = i;
            int j = (end + 1)%n;
            
            while(j != end && nums[i] >= nums[j]) {
                j = (j+1)%n;
            }
            if(j != end) gtr.push_back(nums[j]);
            else gtr.push_back(-1);
        }
        
        return gtr;
    }
};
