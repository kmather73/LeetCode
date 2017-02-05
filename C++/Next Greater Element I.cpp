class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int,int> start;
        for(int i=0; i<nums.size(); ++i) start[nums[i]] = i+1;
        
        vector<int> gtr;
        for(int i=0; i< findNums.size(); ++i){
            int j = start[findNums[i]];
            
            while(j < nums.size() && findNums[i] >= nums[j]) ++j;
            
            if(j < nums.size()) gtr.push_back(nums[j]);
            else gtr.push_back(-1);
        }
        
        return gtr;
    }
};
