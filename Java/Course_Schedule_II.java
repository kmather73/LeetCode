//Time limit error Adj matrix graph
public class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int n = numCourses;
        int[][] graph = new int[n][n];
        
        for(int i=0; i<prerequisites.length; ++i) {
            int x = prerequisites[i][0];  // next class
            int y = prerequisites[i][1];  // prere class
            
            graph[y][x] = 1; // y -> x
        }
        
        return findOrder(graph);
    }

    public int[] findOrder(int[][] graph){
        int n = graph.length;
        
        int[] topOrder = new int[n];
        int[] dfNum = new int[n];
        for(int i=0; i<n; ++i) {
            topOrder[i] = -1;
            dfNum[i] = -1;
        } 
        
        boolean[] cycle = {false};
        int[] currTopOrder = {n-1};
        int[] currDFNum = {0};
        
        for(int i = 0; i < n && !cycle[0]; ++i){
            DFS(graph, i, topOrder, dfNum, currTopOrder, currDFNum, cycle);
        }
        
        
        int[] order;
        
        if(!cycle[0]){
            order = new int[n];
            for(int i = 0; i < n; ++i)
                order[topOrder[i]] = i;
        } else{
            order = new int[0];
        }
            
        return order;
    }
    
    public void DFS(int[][] graph, int node, int[] topOrder, int[] dfNum, int[] currTopOrder, int[] currDFNum, boolean[] cycle){
        if(dfNum[node] != -1 || cycle[0]) {
            return;
        }
        
        ++currDFNum[0];
        dfNum[node] = currDFNum[0];
        
        for(int i = 0; i < graph.length && !cycle[0]; ++i) {
            if(graph[node][i] != 0 && dfNum[i] == -1) {
                DFS(graph, i, topOrder, dfNum, currTopOrder, currDFNum, cycle);
            } else if(graph[node][i] != 0 && dfNum[i] != -1 && topOrder[i] == -1){
                cycle[0] = true;
            }
        }
        
        topOrder[node] = currTopOrder[0];
        --currTopOrder[0];
    }
}
