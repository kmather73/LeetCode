public class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums == null || nums.length == 0)
            return new int[0];
        int numberOfMaxElements = nums.length - k + 1;
        int[] maxList = new int[numberOfMaxElements];
        
        Deque<Tuple> myQueue = new LinkedList<Tuple>();
        myQueue.add( new Tuple(nums[0],0) );
        
        int temp = 0;
        for(int i = 0; i < k; ++i){
            temp = nums[i];
            
            if (temp >= myQueue.peekFirst().val ) {
                myQueue.removeFirst();
                myQueue.addFirst( new Tuple(temp, i) );
            } 
            else {
                while(temp > myQueue.peekLast().val )
                    myQueue.removeLast();
                myQueue.addLast( new Tuple(temp, i)  );
            }
        }
        int position = 0;
        maxList[position] = myQueue.peekFirst().val;
        int upperLimit = nums.length;
        for(int i = k; i < upperLimit ; ++i){
            temp = nums[i];
            
            while(myQueue.size() != 0 && i - myQueue.peekFirst().number >= k)
                myQueue.removeFirst();
            if(myQueue.size() == 0)
                myQueue.addFirst( new Tuple(temp, i) );
            else{
                if(temp >= myQueue.peekFirst().val ) {
                    myQueue.removeFirst();
                    myQueue.addFirst( new Tuple(temp, i) );
                } 
                else {
                    while(temp > myQueue.peekLast().val || i - myQueue.peekLast().number >= k)
                        myQueue.removeLast();
                    myQueue.addLast( new Tuple(temp, i)  );
                }
            }
            maxList[++position] = myQueue.peekFirst().val;
        }
        
        return maxList;
    }
    
    public class Tuple {
        public int val;
        public int number;
        
        public Tuple(int val, int number){
            this.val = val;
            this.number = number;
        }
        
    }
}
