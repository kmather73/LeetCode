public class Solution {
    public int findPeakElement(int[] nums) {
        return findPeakUtill(nums,0, nums.length - 1);
    }
    
    public int findPeakUtill(int[] nums, int left, int right){
        if(left + 1 >= right )
            return nums[left] < nums[right]? right : left;
            
        int mid = (right + left) / 2;
        
        if(nums[left] > nums[mid])
            return findPeakUtill(nums, left, mid);
        else if (nums[right] > nums[mid])
            return findPeakUtill(nums, mid, right);
        else if(nums[mid-1] < nums[mid]  && nums[mid] > nums[mid+1]) 
            return mid;
        else if(nums[mid-1] > nums[mid])
            return findPeakUtill(nums,left, mid - 1);
        else
            return findPeakUtill(nums, mid + 1, right);
    }
}
