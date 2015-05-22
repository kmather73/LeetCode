public class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int index  = m-- + n-- - 1;//position of the last last position in nums1.
        while(n >= 0 && m >= 0){//merge the elements
            if(nums1[m] >= nums2[n]){
                nums1[index--] = nums1[m--];
            }
            else{
                nums1[index--] = nums2[n--];
            }
        }
        while(n >= 0){//copy the elements from nums2 into nums1.
            nums1[index--] = nums2[n--];
        } 
    }
}
