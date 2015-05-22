public class Solution {
    public List<List<Integer>> generate(int numRows) {
        ArrayList<List<Integer>> listOfLists = new ArrayList<List<Integer>>();
        if(numRows == 0){//edge case
            return listOfLists;
        }
        
        ArrayList<Integer> listOne = new ArrayList<Integer>();
        listOne.add(1);//The top of the triangle is a one.
        listOfLists.add(listOne);
        
        for(int i = 0; i < numRows - 1; i++){
            ArrayList<Integer> nextList = new ArrayList<Integer>();//Make a new list of the next level.
            nextList.add(1);//The leftmost element is always a one
            for(int j = 0; j< i; j++){
                nextList.add(listOfLists.get(i).get(j)+listOfLists.get(i).get(j+1));//The binomial coeffice is the sum of the two elements above it in the triangle.
            }
            nextList.add(1);//The rightmost element is always a one.
            listOfLists.add(nextList);//Add the new row to the list.
        }
        return listOfLists;
    }
}
