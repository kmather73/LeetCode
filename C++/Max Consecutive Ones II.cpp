class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size() <= 1 ) return 1;
        else if(nums.size() == 2) return min(2,1 + nums[0] + nums[1] );
        
        vector<int> runs;
        for(int i=0; i<nums.size(); ){
            int m = 0;
            while(i<nums.size() && nums[i] == 1) {
                ++m; ++i;
            }
            runs.push_back(m);
            
            while(i<nums.size() && nums[i] == 0){
              ++i;
              runs.push_back(0);
            } 
        }
        
        int m = runs[0];
        for(int i=1; i<runs.size()-1; ++i){
            if(runs[i] == 0){
                m = max(m, 1 + runs[i-1] + runs[i+1]);
                
            
            }
        }
        
        return m;
    }
};
