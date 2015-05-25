public class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> lastKnowCharPosition = new HashMap<Character, Integer>();
        if(s == null || s.equals("")){
            return 0;
        }
        
        int currStartPosition = 0;
        int longestLength = 1; 
        
        for(int i = 0; i < s.length(); i++){
            if(!lastKnowCharPosition.containsKey(s.charAt(i)) || lastKnowCharPosition.get(s.charAt(i)) < currStartPosition){
                lastKnowCharPosition.put(s.charAt(i), i);
                longestLength = Math.max(longestLength , i - currStartPosition + 1);
            }
            else if(lastKnowCharPosition.get(s.charAt(i)) >= currStartPosition){
                longestLength = Math.max(longestLength, i - currStartPosition);
                currStartPosition = lastKnowCharPosition.get(s.charAt(i)) + 1;
                lastKnowCharPosition.put(s.charAt(i),i);
            }
        }
        return longestLength;
    }
}
