// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int hi = n;
        int low = 0;
        
        while(hi != low){
            int mid = (hi-low)/2 + low;
            
            int res = guess(mid);
            if(!res){
                return mid;
            } else if( res > 0 ){
                low = mid+1;
            } else {
                hi = mid-1;
            }
        }
        
        return hi;
    }
};
