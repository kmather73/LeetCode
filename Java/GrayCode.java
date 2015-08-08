//The gray code sequence is a permutation of the first 2^n integers(starting from zero). This means we have a dricet 
//connection to the group s_{2^n}, since we need the hamming distance of successive terms in the sequence to be one we
//find that the maping we are looking for to be \sigma(k) := k \oplus \frac{k}{2}.
//This map generates the desired perumation.

public class Solution {
    public List<Integer> grayCode(int n) {
        int upperLimit = 1<<n;
        List<Integer> grayCodes = new ArrayList<Integer>(upperLimit);
        
        for(int i = 0; i < upperLimit; ++i){
            grayCodes.add(i ^ (i>>1) );
        }
        return grayCodes;
    }
}
