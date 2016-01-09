public class Solution {
    public boolean isPowerOfThree(int n) {
        return n == 1 || (n > 0 && n%3 == 0 && isPowerOfThree(n/3));
    }
}
