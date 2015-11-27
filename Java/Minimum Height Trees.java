/*Works but  Time Limit Exceeded for the large test cases.*/

public class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> paths = new ArrayList<Integer>();
        int minLength = n;
        if(n <= 1 ){
            paths.add(0);
            return paths;
        }
        
        
        HashMap<Integer, TreeSet<Integer>> edgeMap = new HashMap<Integer, TreeSet<Integer>>();
        
        for(int[] edge : edges){
            if(edgeMap.containsKey(edge[0]))
                edgeMap.get(edge[0]).add(edge[1]);
            else{
                TreeSet<Integer> newSet = new TreeSet<Integer>();
                newSet.add(edge[1]);
                edgeMap.put(edge[0],newSet);
            }
            
            if(edgeMap.containsKey(edge[1]))
                edgeMap.get(edge[1]).add(edge[0]);
            else{
                TreeSet<Integer> newSet = new TreeSet<Integer>();
                newSet.add(edge[0]);
                edgeMap.put(edge[1],newSet);
            }
        }
                            
        for(int i = 0; i < n; ++i){
            int currMin = minPathLength(i, edgeMap);
            if(currMin < minLength){
                minLength = currMin;
                paths.clear();
            }
            if(currMin == minLength)
                paths.add(i);
        }
        return paths;
    }
    
    int minPathLength(int i, HashMap<Integer, TreeSet<Integer>> edges){
        Stack<Integer> myStack = new Stack<Integer>();
        myStack.push(-1);
        return minPathLength(i, edges, myStack);
    }
    
    int minPathLength(int i,HashMap<Integer, TreeSet<Integer>> edges, Stack<Integer> myStack){
        int max = 0;
        TreeSet<Integer> mySet = edges.get(i);
        for(int edge : mySet){
            if(myStack.peek() != edge){
                myStack.push(i);
                max = Math.max(max, 1+minPathLength(edge, edges, myStack));
                myStack.pop();
            }
        }
        return max;
    }
}
