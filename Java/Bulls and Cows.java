public class Solution {
    public String getHint(String secret, String guess) {
        int A = 0, B = 0;
        HashMap<Character,Integer> letterCount = new HashMap<Character, Integer>();
        
        for(int i = 0; i < secret.length(); ++i){
            char c = secret.charAt(i);
            if(letterCount.containsKey(c))
                letterCount.put(c, letterCount.get(c) + 1);
            else
                letterCount.put(c,1);
        }
        
        for(int i = 0; i < secret.length(); ++ i){
            char c1 = secret.charAt(i);
            char c2 = guess.charAt(i);
            
            if(c1 == c2){
                ++A;
                if(letterCount.get(c2) > 0)
                    letterCount.put(c2, letterCount.get(c2) - 1);   
                else
                    --B;
            }
            else if(letterCount.containsKey(c2) &&  letterCount.get(c2) > 0){
                ++B;
                letterCount.put(c2, letterCount.get(c2) - 1);
            }
        }
        return "" + A +"A" + B +"B";
    }
}
