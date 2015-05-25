public class Solution {
    public boolean isHappy(int n) {
        if(n < 1){
            return false;
        }
        
        Set<Integer> myNumbers = new HashSet<Integer>();
        return isHappyHelper(n,myNumbers);
    }
    
    private boolean isHappyHelper(int n, Set<Integer> mySet){
        if(n == 1){
            return true;
        }
        else if(mySet.contains(n)){//Have we generated this number before?
            return false;//Need to stop or will end up in a infinite loop.
        }
        else{
            mySet.add(n);
            n = sumOfDigitsSquard(n);
            return isHappyHelper(n,mySet);
        }
    }
    
    private int sumOfDigitsSquard(int n){
        int sum = 0;
        while(n > 0){
            int temp = n % 10;
            sum = sum + temp * temp;
            n = n/10;
        }
        return sum;
    }
}
