public class Solution {
    public int evalRPN(String[] tokens) {
        if(tokens == null || tokens.length <1){
            return 0;
        }
        char currentChar = ' ';
        int temp1 = 0;
        int temp2 = 0;
        Stack<Integer> stack = new Stack<Integer>();
        Set<Character> operations = new HashSet<Character>();
        operations.add('+');
        operations.add('-');
        operations.add('*');
        operations.add('/');
        
        for(int i = 0; i < tokens.length; ++i){
            currentChar = tokens[i].charAt(0);
            if(!operations.contains(currentChar) || tokens[i].length() > 1 ){
                stack.push(Integer.parseInt(tokens[i]));
            }
            else if(currentChar == '*'){
                temp1 = stack.pop();
                temp2 = stack.pop();
                stack.push(temp1 * temp2);
            }
            else if(currentChar == '/'){
                temp1 = stack.pop();
                temp2 = stack.pop();
                stack.push(temp2 / temp1);
            }
            else if(currentChar == '+'){
                temp1 = stack.pop();
                temp2 = stack.pop();
                stack.push(temp1 + temp2);
            }
            else if(currentChar == '-'){
                temp1 = stack.pop();
                temp2 = stack.pop();
                stack.push(temp2 - temp1);
            }
        }
        return stack.pop();
    }
}
