class Solution {
public:
    bool isPowerOfFour(int num) {
        for(int i = 1,j = 0; i <= num && j < 32/4; ++j, i *= 4){
            if(i == num)
                return true;
        }
        return false;
    }
};
