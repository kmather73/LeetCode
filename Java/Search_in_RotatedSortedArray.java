public class Solution {
    public int search(int[] nums, int target) {
        int startingPoint = findStartingPoint(nums);
        int range = nums.length;

        Coordinates.setOriginAndRange(startingPoint, range);
        
        return binarySearchInNewCoordinates(nums, startingPoint, target);
    }
    
    public int binarySearchInNewCoordinates(int[] nums, int startingPoint, int target){
        int startIndex = startingPoint;
        int endIndex = (nums.length + startingPoint - 1) % nums.length;
        
        while(startIndex != endIndex){
            int midPointInNewCoord =  Coordinates.midPointInNewCoordinates(startIndex,endIndex);
            
            if(nums[midPointInNewCoord] == target){
                return midPointInNewCoord;
            }
            else if(nums[midPointInNewCoord] < target){
                startIndex = (midPointInNewCoord + 1) % nums.length;
            }
            else{
                endIndex = midPointInNewCoord;
            }
        }
        return nums[startIndex] == target ? startIndex : -1;
    }
    
    public int findStartingPoint(int[] num) {
        if(num[0] < num[num.length - 1]){//The array is already sorted.
            return 0;//The smallest element is the leftmost one.
        }
        else{
            return findStartingPointUtill(num, 0, num.length - 1);
        }
    }
    
    public int findStartingPointUtill(int[] num , int start, int end){
        if(start == end || start == end - 1){//Base cases, we are working with only one or two elements.
            return end;//We know that array is in reverse order since we recurse on the part of the array that is not inorder, hence the smaller element is at the end.
        }

        int center = (end + start) / 2; /* should have "center = (end - start)/2 + start" to aovid possible overflow, but current version 
                                       *has better preformance */
        if(num[center] > num[end]){//Is the right half not increasing? 
            return findStartingPointUtill(num, center, end);//recurse on the right half to find the smallest element.
        }
        else{//The left half is not increasing, thus is must contain the smallest element.
            return findStartingPointUtill(num,start,center);//recurse on the left half to find the smallest element.
        }
    }

    
    public static class Coordinates{
        private static int origin;
        private static int range;
        
        public static void setOriginAndRange(int offSet, int upperBound){
            origin = offSet;
            range = upperBound;
        }
        
        public static int oldCoordToNew(int num){
            return num < origin ? (num + range - origin) % range : num;
        }
        
        public static int newCoordToOld(int num){
            return num < range - origin ? num + origin : (num + origin) % range;
        }
        
        public static int midPointInNewCoordinates(int start, int end){
            int midPoint = start + end;
            if(start < origin){
                midPoint += range;
            }
            if(end < origin){
                midPoint += range;
            }
            midPoint = midPoint /  2;
            return midPoint % range;
        }
    }
}
}
