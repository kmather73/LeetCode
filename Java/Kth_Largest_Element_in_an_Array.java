import java.util.Random;
public class Solution {
    public int findKthLargest(int[] nums, int k) {
        return findKthStat(nums,0,nums.length-1, k);// Call the wrapper function.
    }
    
    // The wrapper function that finds the kTh largest statistic. Based on a modified partiton function from quicksort.
    public int findKthStat(int[] nums, int start, int end, int k){
        int index = partition(nums, start, end);
        
        while(index != k - 1){//While we have not found the kTh largest number keep looking.
            if(index > k - 1){//Have found more then the kTh largest numbers, need to narrow our scoop a bit.
                end = index - 1;
            }
            else{//Have found less then the kTh largest numbers, need to expand our scoop a bit.
                start = index + 1;
            }
            index = partition(nums,start,end);//search in a narrow range of numbers.
        }
        return nums[k-1];//Remember we start counting from zero so return (k-1)Th element not the kTh element. 
    }
    
    /*This is a modfied partion function from qiucksort that partitions the larger element to left side of a random pivot and the smaller 
    *element to the right side of the random pivot. It only partions elements from the position "start" to the position "end" in the given     *array */
    public int partition(int[] nums, int start, int end){
        Random random = new Random();
        int randPivot = random.nextInt(end - start + 1) + start;//Pick a random pivot.
        swap(nums,randPivot,end);//Move that pivot to the back for now.
        
        int larger = start;//"large" gives the position of where to swap the next element larger than the pivot. 
        for(int i = start; i <= end; ++i){
            if(nums[i] > nums[end]){//Find the elements that are larger than the pivot.
                if(i != larger)//We only need to swap if "i" is ahead of "larger".
                    swap(nums, larger, i);
                ++larger;//update to the next valid swap position. 
            }
        }
        swap(nums, end, larger);//Put the pivot in its proper place.
        return larger;//Return the index of where the random pivot is placed.
    }
    //Simple function that swaps two number in an array of ints.
    public void swap(int[] nums, int i1, int i2){
        int temp = nums[i1];
        nums[i1] = nums[i2];
        nums[i2] = temp;
    }
}
