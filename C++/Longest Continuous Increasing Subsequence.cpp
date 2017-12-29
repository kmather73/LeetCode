class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int size = 0;
        int i=0;
        
        while(i < nums.size()){
            int j=i;
            while(j+1 < nums.size() && nums[j] < nums[j+1]){
              ++j; 
            }
            
            size = max(size, j-i+1);
            i = j+1;
        }
        return size;
    }
};
