import java.util.Random;
public class Solution {
    public void nextPermutation(int[] nums) {
        int index = findIndex(nums);//Find the index of the array that needs to be swaped with the next largest number to the right of it.
        reOrder(nums,index);//reorder the array so that it is the next largest permutation.
        return;
    }
    
    //This function find the first index from the right where two adjacent digits are out of order, if the idex do not exists return -1.
    public int findIndex(int[] nums){//Find the position of the first element that is out of place if it exists.
        for(int i = nums.length - 1; i != 0; --i){
            if(nums[i] > nums[i-1]){return i - 1;}//Return the first out of order position.
        }
        return -1;//The array is in reverse order
    }
    //This function reorders the array so that it is the next largest permutation of its digits.
    public void reOrder(int[] nums, int index){
        if(index != -1){
            int toSwap = nextLargestIndex(nums,index);//Find the successor of nums[index] in nums[].
            swap(nums, index, toSwap);
        }
        sort(nums, index + 1, nums.length - 1);//Rearrange the number to the right to form the smallest possible number
    }
    
    //This funtions finds the index of the successor of nums[index] in the range [index , nums.length).
    public int nextLargestIndex(int[] nums, int index){
        int larger = nums[index + 1];//value of the best know successor value.
        int successor = index + 1;// index of the best know successor.
        
        for(int i = index + 2; i < nums.length; ++i){//Find the successor.
            if(nums[i] > nums[index] && larger > nums[i] ){//Found a better successor.
                larger = nums[i];//update the best know successors value.
                successor = i;// Update the best known successor so far.
            }
        }
        return successor;
    }
    
    public void sort(int[] nums, int start, int end){//Sort the array.
        if(start == -1){//The array is in reverse order, we can sort in linear time!
            for(int i = 0; i < nums.length/2; ++i){
                swap(nums, i, end - i);
            }
            return;
        }
        if(start >= end){return;}//Base case.
        
        int pivot = partition(nums, start, end);//QuickSort
        sort(nums, start, pivot - 1);//Recursive call
        sort(nums, pivot + 1, end);//Recursive call
        return;
    }
    
    public int partition(int[] nums, int start, int end){
        Random random = new Random();
        int randPivot = random.nextInt(end - start + 1) + start;//Pick a random pivot.
        swap(nums,randPivot,end);//Move that pivot to the back for now.
        
        int smaller = start;//"smaller" gives the position of where to swap the next element smaller than the pivot. 
        for(int i = start; i < end; ++i){
            if(nums[i] < nums[end]){//Find the elements that are smaller than the pivot.
                if(i != smaller)//We only need to swap if "i" is ahead of "smaller".
                    swap(nums, smaller, i);
                ++smaller;//update to the next valid swap position. 
            }
        }
        swap(nums, end, smaller);//Put the pivot in its proper place.
        return smaller;//Return the index of where the random pivot is placed.
    }
    //Simple function that swaps two number in an array of ints.
    public void swap(int[] nums, int i1, int i2){
        int temp = nums[i1];
        nums[i1] = nums[i2];
        nums[i2] = temp;
    }
}
