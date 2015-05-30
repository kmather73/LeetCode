public class Solution {
    public String convertToTitle(int n) {
        String column = "";
        char nextCharacter = 'A';
        int remainder = 0;

        while( n > 0){
            remainder = (n - 1) % 26;
            nextCharacter = (char) ('A' + remainder );
            column = nextCharacter + column  ;
            n = (n - 1) / 26;
        }
        return column;
    }
}
