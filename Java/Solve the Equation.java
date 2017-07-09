public class Solution {
    public String solveEquation(String equation) {
    
        int i=0;
        while(equation.charAt(i) != '=') ++i;
        
        String eqLeft = equation.substring(0, i);
        String eqRight = equation.substring(i+1);
        
        int left[] = getParts(eqLeft);
        int right[] = getParts(eqRight);
        
        
        int ax = left[0] - right[0];
        int b = right[1] - left[1];
        
        if(ax == 0 && b != 0) return "No solution";
        else if(ax == 0 && b == 0) return "Infinite solutions";
        String str = "x=";
        int ans = b / ax;
        str = str +"" + ans;
        return str;
    }
    
    int[] getParts(String str){
        
        int i=0;
        int sum = 0;
        int coeff[] = new int[2];
        int sign = 1;
        int len = 0;
        while(i < str.length()){
            if(str.charAt(i) == 'x'){
                if(len == 0){
                    coeff[0] += sign;
                } else {
                    coeff[0] += sign * sum;
                }
                sum = 0;
                ++i;
                if(i == str.length()) break;
            } 
            
            if(str.charAt(i) == '+'){
                coeff[1] += sign*sum;
                sign = 1;
                sum = 0;
                len = 0;
            } else if(str.charAt(i) == '-'){
                coeff[1] += sign*sum;
                sign = -1;
                sum = 0;
                len = 0;
            } else {
                sum *= 10;
                sum += str.charAt(i) - '0';
                len += 1;
            }
            ++i;
        }
        
        coeff[1] += sign*sum;
        
        return coeff;
    }   
}
