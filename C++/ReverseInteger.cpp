class Solution {
public:
    int reverse(int x) {
        int sum = 0;
        int lowerBound = INT_MAX/10;
        int upperBound = INT_MIN/10;
        
        while(x!=0){
            if(sum > lowerBound || sum < upperBound)
                return 0;
            sum = sum * 10 + x % 10;
            x /= 10;
        }
        return sum;
    }
};
