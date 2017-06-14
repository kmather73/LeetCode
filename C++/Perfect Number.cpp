class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1) return false;
        int sum = 1, i;

        for(int i=2; i*i < num; ++i){
            if(num % i == 0) {
                sum += i + num/i;
            }
        }
        
        sum += (i*i == num)*i;
        return sum == num;
    }
};
