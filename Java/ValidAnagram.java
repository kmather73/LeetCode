public class Solution {
    public boolean isAnagram(String s, String t) {
        int lengthOfS = s.length();
        int lengthOfT = t.length();
        
        if(lengthOfS != lengthOfT)
            return false;
        
        HashMap<Character, Integer> countsOfCharsInS = new HashMap<Character, Integer>();
        
        for(int i = 0; i < lengthOfS; ++i){
            char c = s.charAt(i);
            if(countsOfCharsInS.containsKey(c))
                countsOfCharsInS.put(c, 1 + countsOfCharsInS.get(c));
            else
                countsOfCharsInS.put(c,1);
        }
        
        for(int i = 0; i < lengthOfT; ++i){
            char c = t.charAt(i);
            if(!countsOfCharsInS.containsKey(c) || countsOfCharsInS.get(c) == 0)
                return false;
            else
                countsOfCharsInS.put(c, countsOfCharsInS.get(c) - 1);
        }
        return true;
    }
}
