class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        
        //Find the rotation point in the array
        while (left < right) {
            int mid = (right - left)/2 + left;
            
            if( nums[right] < nums[mid] )
                left = mid + 1;
            else
                right = mid;
        }
        
        int rotPoint = left;
        
        left = 0; 
        right = nums.size()-1;
        
        while(left <= right){
            int mid = (right-left)/2 + left;
            int rotMid = (mid + rotPoint)%n;
            
            if( nums[ rotMid ] == target)
                return rotMid;
            else if( nums[ rotMid ] < target )
                left = mid+1;
            else
                right = mid-1;
        }
        
        return -1;
        
    }
};
