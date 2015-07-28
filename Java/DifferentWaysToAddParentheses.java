public class Solution {
    public List<Integer> diffWaysToCompute(String input) {
        ArrayList<Integer> nums = new ArrayList<Integer>();
        ArrayList<Character> ops = new ArrayList<Character>();
        
        generateSymboles(nums, ops, input);

        return diffWaysUtill(ops, nums, 0, nums.size()-1);
    }
    
    public List<Integer> diffWaysUtill( List<Character> ops, List<Integer> nums, int numsBegin, int numsEnd){
        ArrayList<Integer> possibleNums = new ArrayList<Integer>();
        if(numsBegin == numsEnd){
            possibleNums.add(nums.get(numsBegin));
            return possibleNums;   
        }
        /* Add this part and move the above case into the calling function for a speed up.
        *if(numsBegin + 1 == numsEnd){
        *    int temp = nums.get(numsBegin);
        *    char c = ops.get(numsBegin);
        *    if( c== '+')
        *        temp += nums.get(numsEnd);
        *    else if(c == '-')
        *        temp -= nums.get(numsEnd);
        *    else
        *        temp *= nums.get(numsEnd);
        *   possibleNums.add(temp);
        *    return possibleNums;
        *}
        */
        
        for(int i = numsBegin; i < numsEnd; ++i){
            List<Integer> leftSide = diffWaysUtill( ops, nums, numsBegin, i);
            List<Integer> rightSide = diffWaysUtill( ops, nums, i+1, numsEnd);
            
            char operation = ops.get(i);
            possibleNums.addAll( mergeListsWithOperation(leftSide, rightSide, operation) );
        }
        return possibleNums;
    }
    
    public void generateSymboles(ArrayList<Integer> nums, ArrayList<Character> ops, String input){
        TreeSet<Character> validOps = new TreeSet<Character>() {{ add('+'); add('-'); add('*'); }};
        
        int length = input.length();
        
        int start = 0;
        for(int i = 0; i < length; ++i){
            char c = input.charAt(i);
            if(validOps.contains(c)){
                ops.add(c);
                nums.add(Integer.parseInt(input.substring(start, i)) );
                start = i + 1;
            }
        }
        nums.add(Integer.parseInt(input.substring(start, length)));
    }
    
    public List<Integer> mergeListsWithOperation(List<Integer> leftSide, List<Integer> rightSide, char operation){
        int leftSize = leftSide.size();
        int rightSize = rightSide.size();
        List<Integer> merged = new ArrayList<Integer>(leftSize * rightSize);

        if(operation == '+')
            for(int i = 0; i < leftSize; ++i)
                for(int j = 0; j < rightSize; ++j)
                    merged.add(leftSide.get(i)+rightSide.get(j));
        else if(operation == '-') 
            for(int i = 0; i < leftSize; ++i)
                for(int j = 0; j < rightSize; ++j)
                    merged.add(leftSide.get(i)-rightSide.get(j));          
        else
            for(int i = 0; i < leftSize; ++i)
                for(int j = 0; j < rightSize; ++j)
                    merged.add(leftSide.get(i)*rightSide.get(j));          
        
        return merged;
    }
}
