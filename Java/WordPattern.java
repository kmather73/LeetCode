public class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] words = str.split(" ");
        
        if(words.length != pattern.length())
            return false;
            
        HashMap<String, Character> index = new HashMap<String, Character>();
        HashMap<Character, String> index2 = new HashMap<Character, String>();
        
        for(int i = 0; i < pattern.length(); ++i){
            Character c = pattern.charAt(i);
            
            if(index.containsKey(words[i]) && !c.equals(index.get(words[i])) ||
                            index2.containsKey(c) && !words[i].equals(index2.get(c)))
                return false;
            
            index.put(words[i], c);
            index2.put(c, words[i]);
        }
        return true;
    }
}

/* does not work if one word is mapped to multiple characterS.
public class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] words = str.split(" ");
        
        if (words.length != pattern.length())
            return false;
            
        int[] index = new int[26];
        
        for(int i = 0; i < pattern.length(); ++i){
            char c = pattern.charAt(i);
            
            if(index[c - 'a'] == 0)
                index[c - 'a'] = i + 1;
            else
                if(! words[i].equals(words[index[c-'a'] - 1]) )
                    return false;
        }
        return true;
    }
}
*/
