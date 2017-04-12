public class Solution {
    public String reverseWords(String s) {
        String[] words = s.split(" ");
        String st = "";
        
        for(int i=0; i< words.length-1; ++i){
            st += new StringBuilder(words[i]).reverse().toString() + " ";
        }
        
        st += new StringBuilder(words[words.length-1]).reverse().toString();
        
        return st;   
    }
}
