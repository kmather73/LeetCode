class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        int k = max(m, n);
        
        string str;
        str.resize(k);
        
        int i = n-1, j = m-1;
        
        
        char carry = 0;
        while(i>= 0 || j >= 0){
            char sum = carry;
            if(i >= 0){
                sum += num1[i] - '0';
                --i;
            }
            
            if(j >= 0) {
                sum += num2[j] - '0';
                --j;
            }
            
            --k;
            str[k] = (sum%10) + '0';
            carry = sum / 10;
        }
        
        if(carry){
            str = "1" + str;
        }
        
        return str;
    }
};
