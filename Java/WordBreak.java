public class Solution {
    public boolean wordBreak(String s, Set<String> dict) {
       if(s == null || s.length()<1){
           return false;
       }
       if(dict.contains(s)){//If the dictionary contains our word then we are done.
           return true;
       }
       
       boolean[] canBreakHere = new boolean[s.length()+1];//Set of the DP. canBreakHere[i] tells us whether or not we the substring s.substring(0,i) can be broken into valid words. 
       canBreakHere[0] = true;//Boundary condition.
       
       for(int i = 0; i < s.length(); ++i){
            for(int j = i + 1; j <= s.length(); ++j){
                if(dict.contains(s.substring(i,j) ) ){// Is the current substring a valid word?
                    canBreakHere[j] = true;//Remember that we can break here.
                }
            }
            while(i < s.length() && !canBreakHere[i+1]){//advance our starting point to the next point we know we can break.
                ++i;
            }
       }
       return canBreakHere[s.length()];
    }
}
