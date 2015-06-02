public class Solution {
    public int lengthOfLastWord(String s) {
        boolean lastCharFound = false;
        int end = 0;
        
        for(int i = s.length() - 1; i >= 0; --i){
            char c = s.charAt(i);
            if(c != ' ' && !lastCharFound){
                end = i + 1;
                lastCharFound = true;
            }
            else if(c == ' ' && lastCharFound){
                return end - i - 1;
            }
        }
        return end;
    }
}
