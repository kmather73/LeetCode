public class Solution {
    public List<List<Integer>> palindromePairs(String[] words) {
        List<List<Integer>> pals = new ArrayList<List<Integer>>();
        ArrayList<Integer> temp = null;
        for(int i = 0; i < words.length; ++i){
            for(int j = 0; j < words.length; ++j){
                if(i!= j && isPalindrome(words[i], words[j])){
                    temp = new ArrayList<Integer>(2);
                    temp.add(i);
                    temp.add(j);
                    pals.add(temp);
                }
            }
        }
        
        return pals;
    }
    
    public boolean isPalindrome(String word_front, String word_end){
        boolean isPal = true;
        int len = word_front.length() + word_end.length();
        int lenBy2 = len/2;
        
        int i = 0;
        int j = word_end.length()-1;
        
        
        for(int k = 0; k < lenBy2 && isPal; ++k){
            if(i == word_front.length()){
                i = 0;
                word_front = word_end;
            } 
            
            if(j == -1){
                j = word_front.length()-1;
                word_end = word_front;
            }
            
            if(word_front.charAt(i) != word_end.charAt(j)){
                isPal = false;
            }
            ++i;
            --j;
        }
        return isPal;
    }
}
