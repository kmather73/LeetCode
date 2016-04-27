public class Solution {
    public String reverseWords(String s) {
        String[] words = s.trim().split(" +");
        String rev = "";
        
        for(int i = words.length-1; i >= 0; --i)
            rev += " " + words[i];
            
        return rev.trim();
    }
}
