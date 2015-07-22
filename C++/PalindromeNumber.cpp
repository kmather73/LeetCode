class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0)
            return false;
        int power = 1;
        while(x/power >= 10 )
            power *= 10;
        
        int firstDigit = 0, lastDigit = 0;
        
        while(x && firstDigit == lastDigit){
            lastDigit = x % 10;
            firstDigit = x/power;
            x = (x%power)/10;
            power /=100;
        }
        
        return x == 0 && firstDigit == lastDigit;
    }
};
