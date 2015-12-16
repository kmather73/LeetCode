public class Solution {
    public int maxProduct(String[] words) {
        int[] bitSet = new int[words.length];
        int max = 0;
        for(int i = words.length-1; i >= 0; --i){
           bitSet[i] = giveSigniture(words[i]); 
        
            for(int j = words.length-1; j > i; --j)
                if((bitSet[i]&bitSet[j]) == 0)
                    max = Math.max(max, words[i].length()* words[j].length());
        }
        return max;
    }
    
    /* Give a bit signiture to each word. 
     * Have bit i set to 1 if the i'th letter in the alphabet appears in the word and 0 otherwise
     */
    public int giveSigniture(String str){
        int sig = 0;
        for(int i = str.length()-1; i >= 0; --i){
            int mask = 1<<(str.charAt(i) - 'a');
            
            sig |= mask;
        }
        return sig;
    }
}


/* Below is a good theoretical solution*/
public class Solution {
    public int maxProduct(String[] words) {
        HashMap<Integer, Double> table = new HashMap<Integer, Double>();
        table.put(0, -1.0);
        
        for(String str : words){
            if(str.equals(""))
                continue;
                
            int sig = giveSigniture(str);
            writeTable(sig, Math.log(str.length()), table);
        }
        
        return (int)Math.round(Math.exp(table.get(0)));
    }
    
    /* Give a bit signiture to each word. 
     * Have bit i set to 1 if the i'th letter in the alphabet appears in the word and 0 otherwise
     */
    public int giveSigniture(String str){
        int sig = 0;
        for(int i = str.length()-1; i >= 0; --i){
            int mask = 1<<(str.charAt(i) - 'a');
            
            sig |= mask;
        }
        return sig;
    }
    
    public static void writeTable(int sig, double value, HashMap<Integer, Double> table){
        if(!table.containsKey(sig) || value > table.get(sig))
            table.put(sig, value);

        ArrayList<Integer> past = new ArrayList<Integer>();
        ArrayList<Integer> next = new ArrayList<Integer>();
        ArrayList<Integer> temp;

        int newSig = (~sig)&0x3FFFFFF; //This gives the largers set of letters that are not contained in the current word.
        past.add(newSig);

        double max = table.get(0);
        if(table.containsKey(newSig))
            max = Math.max(max, value + table.get(newSig));

        for(int i = 0; i < 26; ++i){
            int mask = 1<<i;
            
            for(int num: past){
                int num2 = num&(~mask); //Make the i'th bit set to 0.

                next.add(num);
                if(num2 > 0 && num2 != num)
                    next.add(num2);

                //See if there are any words so far that have no leeters in common with the current word
                if(num2 > 0 && table.containsKey(num2)) 
                    max = Math.max(max, value + table.get(num2));
            }
            temp = past;
            past = next;
            next = temp;
            next.clear();

        }
        table.put(0, max);
    }
}
