public class Solution {
    public final static String[] ones  = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine"};
    
    public final static String[] tens = {""," Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
    
    public final static String[] teens = {"", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen",
                                            " Seventeen", " Eighteen", " Nineteen"};
    public final static String[] postfixs = {" Hundred", " Thousand", " Million", " Billion"};
    
    public final static int[] decimalPlaces = {100, 1000, 1000000, 1000000000}; 
                                      // "==" {Hundreds, Thousands, Millions, Billions}
                                      
                                      
    public String numberToWords(int num) {
        if(num == 0)
            return "Zero";
            
        StringBuffer numStr = new StringBuffer();
        
        for(int i = 3, infix = 0; i >= 0; --i){
            infix = num / decimalPlaces[i];
            num %= decimalPlaces[i];
            
            if(infix > 0)
                numStr.append( getInfix(infix) ).append( postfixs[i % 10] );
        }
        numStr.append( getInfix(num) );
        return numStr.toString().trim();
    }
    
    //This funtion assumes that the input number is in the range of [0, 999] and returns a string of english words representing the number
    public StringBuffer getInfix(int num){
        if(num <= 0)
            return new StringBuffer(0);
            
        StringBuffer s = new StringBuffer();
        
        int index = num / 100;
        num %= 100;
        
        if(index > 0){
            s.append(ones[index]);
            s.append(" Hundred");
        }
        
        index = num / 10;
        num %= 10;
        
        if(index == 1 && num > 0){
            s.append(teens[num]);
            return s;
        }
      
        s.append(tens[index]).append(ones[num]);
        return s;
    }
}
