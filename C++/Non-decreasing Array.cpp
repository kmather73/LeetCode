class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int rev = 0;
        int m1=nums[0], m2=INT_MIN;
        for(int i=1; i<nums.size() && rev<=1; ++i){
            if(m1 > nums[i]) {
                ++rev;
                if(nums[i] >= m2) m1 = nums[i];
                
            } else{
                m2 = m1;
                m1 = nums[i];
            }
        }
        
        return rev <= 1;
    }
};
