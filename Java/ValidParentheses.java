public class Solution {
    public boolean isValid(String s) {
        if (s.length() % 2 != 0) return false;
    
        HashMap<Character,Character> matchingParensMap = new HashMap<Character, Character>();
        matchingParensMap.put(')' , '(');
        matchingParensMap.put('}' , '{');
        matchingParensMap.put(']' , '[');  
    
        Stack<Character> stackOfParen = new Stack<Character>();
        
        for (char ch : s) {
            if(matchingParensMap.containsValue( ch ) {
                stackOfParen.push( ch );
            } else if( stackOfParen.empty() || matchingParensMap.get( ch ) != stackOfParen.pop() ) {
                return false;
            }
        }
        return stackOfParen.empty();
    }
}
