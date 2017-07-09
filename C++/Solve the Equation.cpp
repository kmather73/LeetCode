class Solution {
public:
    vector<int> getParts(string& str){
        
        int i=0;
        int sum = 0;
        vector<int> coeff {0, 0};
        int sign = 1;
        int len = 0;
        while(i < str.size()){
            if(str[i] == 'x'){
                if(len == 0){
                    coeff[0] += sign;
                } else {
                    coeff[0] += sign * sum;
                }
                sum = 0;
                ++i;
                if(i == str.size()) break;
            } 
            
            if(str[i] == '+'){
                coeff[1] += sign*sum;
                sign = 1;
                sum = 0;
                len = 0;
            } else if(str[i] == '-'){
                coeff[1] += sign*sum;
                sign = -1;
                sum = 0;
                len = 0;
            } else {
                sum *= 10;
                sum += str[i] - '0';
                ++len;
            }
            ++i;
        }
        
        coeff[1] += sign*sum;
        
        return coeff;
    }
    
    string solveEquation(string equation) {
        int i;
        while(equation[i] != '=') ++i;
        
        string eqLeft = equation.substr(0, i);
        string eqRight = equation.substr(i+1);
        
        vector<int> left = getParts(eqLeft);
        vector<int> right = getParts(eqRight);
        
        
        int ax = left[0] - right[0];
        int b = right[1] - left[1];
        
        if(ax == 0 && b != 0) return "No solution";
        else if(ax == 0 && b == 0) return "Infinite solutions";
        string str = "x=";

        str += to_string(b / ax);
        return str;
    }
};
