public class Solution {
    public int climbStairs(int n) {
        int previousStep = 0;
        int currentStep = 1;
        int temp = 0;
        
        for(int i = 0; i < n; ++i){
            temp = currentStep;
            currentStep = currentStep + previousStep;
            previousStep = temp;
        }
        return currentStep;
    }
}
