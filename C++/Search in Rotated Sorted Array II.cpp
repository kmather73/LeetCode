class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int mid;
        
        while(left < right) {
            mid = (left + right)/2;
          
            if (nums[ mid ] == target )
                return true;
                
            else if( nums[ mid ] > nums[right] ) {
                if( nums[ mid ] > target && nums[ left ] <= target) 
                    right = mid;
                else 
                    left = mid + 1;
                
            } else if( nums[ mid ] < nums[ right ]) {
                if( nums[ mid ] < target && nums[ right ] >= target) 
                    left = mid + 1;
                else
                    right = mid;
            } else {
                --right;
            }
        }
        return nums[ left ] == target ;
    }
};
