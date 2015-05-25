public class Solution {
    public int titleToNumber(String s) {
        if(s == null || s.length() < 1){
            return 0;
        }

        int columnNumber = 0;
        for(int i = 0; i < s.length(); ++i){
            columnNumber = columnNumber*26 + s.charAt(i) - 'A' + 1;
        }
        return columnNumber;
    }
}
