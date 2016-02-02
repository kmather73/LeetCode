public class Solution {
    public boolean isValidSerialization(String preorder) {
        int hashCount = 0;
        int nodeCount = 0;
        int level = 0;

        String[] tree = preorder.split("[,]");
        for(int i = 0; i < tree.length-1; ++i){
            if( !tree[i].equals("#") ){
                ++nodeCount;
                ++level;
            }
            else {
                ++hashCount;
                 if(level ==  0)
                    return false;
                 --level;
            }
        }
        return hashCount == nodeCount && tree[tree.length-1].equals("#");
    }
}
