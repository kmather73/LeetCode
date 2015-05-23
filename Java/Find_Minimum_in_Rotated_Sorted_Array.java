public class Solution {
    public int findMin(int[] num) {
        if(num[0] < num[num.length-1]){//The array is already sorted.
            return num[0];//The smallest element is the leftmost one.
        }
        else{
            return findMin(num,0, num.length -1);// Call The wrapper function
        }
    }
    
    public int findMin(int[] num , int start, int end){
        if(start == end || start == end - 1){//Base case, we are working with only one or two elements.
            return num[end];//We know that array is in reverse order since we recurse the part of the array that is not inorder, hence the smaller element is at the end.
        }

        int center = (end + start)/2; /* should have "center = (end - start)/2 + start" to aovid possible overflow, but current version 
                                       *has better preformance */
        if(num[center] > num[end]){//Is the right half not increasing? 
            return findMin(num, center, end);//recurse on the right half to find the smallest element.
        }
        else{//The left half is not increasing, thus is must contain the smallest element.
            return findMin(num,start,center);//recurse on the left half to find the smallest element.
        }
    }
}
