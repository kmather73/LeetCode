public class Solution {
    public boolean isAnagram(String s, String t) {
        int lengthOfS = s.length();
        int lengthOfT = t.length();
        
        if(lengthOfS != lengthOfT)
            return false;
        
        
        int[] countsOfCharsInS = new int[26];
        for(int i = 0; i < lengthOfS; ++i){
            char c = s.charAt(i);
            ++countsOfCharsInS[c - 'a'];
        }
        
        for(int i = 0; i < lengthOfT; ++i){
            char c = t.charAt(i);
            if(countsOfCharsInS[c - 'a'] == 0)
                return false;
            
            --countsOfCharsInS[c - 'a'];
        }
        return true;
    }
}
