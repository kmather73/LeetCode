public class Solution {
    public boolean isValid(String s) {
        if(s.length() % 2 != 0){return false;}
    
        HashMap<Character,Character> matchingParensMap = new HashMap<Character, Character>();//Build thecorrespondence between the parentheses
 
        matchingParensMap.put(')' , '(');
        matchingParensMap.put('}' , '{');
        matchingParensMap.put(']' , '[');  
    
        Stack<Character> stackOfParen = new Stack<Character>();//Stack to hold the running set of left parentheses.
        
        for(int i = 0; i < s.length(); ++i){
            if(matchingParensMap.containsValue( s.charAt(i) ) ){//If we see a left paren keep track of it.
                stackOfParen.push(s.charAt(i));
            }
            else if( stackOfParen.empty() || matchingParensMap.get(s.charAt(i)) != stackOfParen.pop() )// Does the right paren mack with the last seen left paren?
                return false;
        }
        return stackOfParen.empty();//Do we have any left parentheses left?
    }
}
