public class Solution {
    public boolean isPalindrome(String s) {
      int left = 0;
      int right = s.length() -1 ;
           

      while(left < right){
        while(left < s.length() &&  notValidChar(s, left) )
            ++left;
        
        while(right >= 0 &&  notValidChar(s, right) )
            --right;
            
        if( right > left && notMatchingChar(s, left, right) )
            return false;
        ++left;
        --right;
      }
      return true;
    }
    
    private boolean notValidChar(String s, int position){
        char c = s.charAt(position);
        return !( c >= 'A' && c <= 'Z') && !( c >= 'a' && c <= 'z') && !( c >= '0' && c <= '9');
    }
    
    private boolean notMatchingChar(String s, int left, int right){
        return s.charAt(left) != s.charAt(right) && s.charAt(left) != (s.charAt(right) - 'A' + 'a') && s.charAt(left) != (s.charAt(right) + 'A' - 'a');
    }
}
