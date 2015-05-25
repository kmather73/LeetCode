public class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s == null && t == null){
            return true;
        }
        else if(s == null || t == null){
            return false;
        }
        else if(s.length() != t.length()){
            return false;
        }
        
        char charFromS = ' ';
        char charFromT = ' ';
        HashMap<Character,Character> correspondence = new HashMap<Character,Character>();
        
        for(int i = 0; i < s.length(); i++){
            charFromS = s.charAt(i);
            charFromT = t.charAt(i);
            
            //Does there already exist a correspondence between the two characters
            if(!correspondence.containsKey(charFromS) && !correspondence.containsValue(charFromT)){
                correspondence.put(charFromS, charFromT);
            }
            else if( (correspondence.containsKey(charFromS) && (charFromT != correspondence.get(charFromS) ) )){
                return false; // The two ccharcters doe not correspond to each other
            }
            else if(!correspondence.containsKey(charFromS) && correspondence.containsValue(charFromT) ){
                return false; // The two ccharcters doe not correspond to each other
            }
        }
        return true;
    }
}
