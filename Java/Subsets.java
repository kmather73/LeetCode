//Cleaner version at the bottom, fastter one at the top.
public class Solution {
    public List<List<Integer>> subsets(int[] S) {
        HashSet<List<Integer>> someSubsets = subsets(S, 0);//Call the wrapper function.
        List<List<Integer>> listOfSets = new ArrayList<List<Integer>>(someSubsets);//Convert the set to a list.
        return listOfSets;
    }
    
    //Recursive wrapper function to find the powerset of a given set.
    public HashSet<List<Integer>> subsets(int[] S, int start){
        HashSet<List<Integer>> allSubsets = new HashSet<List<Integer>>();
        
        if(start == S.length){//Base case, working with the empty set.
            List<Integer> mySets = new ArrayList<Integer>();
            allSubsets.add(mySets);
        }
        else{//Our set is nonempty.
            allSubsets = subsets(S, start + 1);//find the power set of the set not including the first element.
            int item = S[start];//take the first element to merge with the other sets.
            HashSet<List<Integer>> moreSubset =  new HashSet<List<Integer>>();//make a copy of the sets to merge.
            
            for(List<Integer> sets : allSubsets){//Merge the first element with the other sets
                ArrayList<Integer> newSubset = new ArrayList<Integer>(sets);
                
                int position = 0;//position of where to inset the first element into the list.
                for(int i = 0; i < sets.size(); ++i){
                    if(sets.get(i)>item){break;}
                    ++position;
                }
                newSubset.add(position,item);// insert at the right position.
                moreSubset.add(newSubset);// at set to collection.
            }
            allSubsets.addAll(moreSubset);//merge the new sets with the previous ones.
        }
        return allSubsets;
    }
}


/* Cleaner version that uses the Collections.sort method to make sure elments are in the right order.
* The other version calculate where to inset the item in the right place instead of sorting the whole list. */
    public List<List<Integer>> subsets(int[] S) {
        HashSet<List<Integer>> someSubsets = subsets(S, 0);//Call the wrapper function.
        List<List<Integer>> listOfSets = new ArrayList<List<Integer>>(someSubsets);//Convert the set to a list.
        return listOfSets;
    }
    
    //Recursive wrapper function to find the powerset of a given set.
    public HashSet<List<Integer>> subsets(int[] S, int start){
        HashSet<List<Integer>> allSubsets = new HashSet<List<Integer>>();
        
        if(start == S.length){//Base case, empty set.
            List<Integer> mySets = new ArrayList<Integer>();
            allSubsets.add(mySets);
        }
        else{//out set is nonempty.
            allSubsets = subsets(S, start + 1);//find the power set of the set not including the first element.
            int firstItem = S[start];//take the first element to merge with the other sets.
            HashSet<List<Integer>> moreSubset =  new HashSet<List<Integer>>();//make a copy of the sets to merge.
            
            
            for(List<Integer> sets : allSubsets){//Merge the first element with the other sets
                ArrayList<Integer> newSubset = new ArrayList<Integer>(sets);
                newSubset.add(firstItem);//Inset the new item
                Collections.sort(newSubset);//make sure the new element is in the right position.
                moreSubset.add(newSubset);// at set to collection.
            }
            allSubsets.addAll(moreSubset);//merge the new sets with the previous ones.
        }
        return allSubsets;
    }
