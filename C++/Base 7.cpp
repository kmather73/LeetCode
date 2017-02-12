class Solution {
public:
    string convertTo7(int num) {
        if(num == 0) return "0";
        string str ="";
        
        if(num < 0) return "-" + convertTo7(-num);
        while( num > 0){
            int rem = num % 7;
            num = num/7;
            
            str = to_string(rem) + str;
        }
        return str;
    }
};
