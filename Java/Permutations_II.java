public class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        Permutation permutations = new Permutation(nums);
        permutations.generatePermutations();
        return permutations.ListOfPermutations();        
    }
    

    public class Permutation{
        private boolean[] taken;
        private int[] nums;
        public int[] positions;
        private int count;
        
        private int size;
        public  Set<List<Integer>> permutations;
        
        public Permutation(int[] otherNums){
            size = otherNums.length;
            count = 0;
            
            taken = new boolean[size];
            positions = new int[size];
            
            nums = new int[size];
            for(int i = 0; i < size; ++i){
                nums[i] = otherNums[i];
            }
            
            permutations = new HashSet<List<Integer>>();
        }
        
        public void generatePermutations(){
            if(count == size){
               ArrayList<Integer> newPerms = new ArrayList<Integer>(size);
               for(int i = 0; i <size; ++i){
                   newPerms.add(positions[i]);
               }
                permutations.add(newPerms);
            }
            else{
                ++count;
                for(int i = 0; i < size; ++i){
                    if(!taken[i]){
                        taken[i] = true;
                        positions[i] =  nums[count-1];
                        generatePermutations();
                        taken[i] = false;
                    }
                }
                --count;
            }
        }
        
        public List<List<Integer>> ListOfPermutations(){
            return new ArrayList(permutations);
        }
    }
}
