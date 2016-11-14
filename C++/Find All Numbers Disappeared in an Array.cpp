class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        
        for(int i=0; i<nums.size(); ++i){
            int j = i;
            
            while(nums[j] >= 1 && nums[j] != j+1){
                swap(nums[j], nums[nums[j]-1]);
                if(nums[nums[j]-1] == nums[j]) nums[nums[j]-1] = -1;
            }
        }
        
        
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] == -1) ans.push_back(i+1);
        }
        
        return ans;
    }
};
