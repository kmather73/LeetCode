public class Solution {
    public String longestPalindrome(String word) {
        if(word == null || word.length() < 2 ){
            return word;
        }
        
        String largest = "";
        String largestOdd = longestOddLengthPalindrome(word);
        String largestEven = longestEvenLengthPalindrome(word);
        
        if(largestOdd.length() < largestEven.length() ){
            largest = largestEven;
        }
        else{
            largest = largestOdd;
        }
        return largest;
    }
    
    public String longestOddLengthPalindrome(String word){
        int currMaxLength = 0;
        String maxSubString = "";
        
        for(int i = 0; i < word.length(); ++i){
            int[] currSubStringLength = palindroneAt(word, i, i);
            
            if(currSubStringLength[0] > currMaxLength){
                currMaxLength = currSubStringLength[0];
                maxSubString = word.substring(currSubStringLength[1], currSubStringLength[2] + 1);
            }
        }
        return maxSubString;
    }
    
    public String longestEvenLengthPalindrome(String word){
        int currMaxLength = 0;
        String maxSubString = "";
        
        for(int i = 0; i < word.length()- 1; ++i){
            int[] currSubStringLength = palindroneAt(word, i, i + 1);
            if(currSubStringLength[0] > currMaxLength){
                currMaxLength = currSubStringLength[0];
                maxSubString = word.substring(currSubStringLength[1], currSubStringLength[2] + 1);
            }
        }
        return maxSubString;
    }
    
    public int[] palindroneAt(String word, int start, int end){
        int[] Arr = new int[3];
        
        while( (start >= 0) && (end < word.length()) && (word.charAt(start) == word.charAt(end)) ){
            --start;
            ++end;
        }
        Arr[1] = start + 1;
        Arr[2] = end - 1;
        Arr[0] = end - start + 1;
        return Arr;
        
    }
}
