public class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        if(prerequisites.length == 0)
            return true;
        int n = numCourses;
        int[][] graph = new int[n][n];
        
        for(int i=0; i<prerequisites.length; ++i) {
            int x = prerequisites[i][0];  // next class
            int y = prerequisites[i][1];  // prere class
            
            graph[y][x] = 1; // y -> x
        }
        
        return !detectCycle(graph);
    }

    public boolean detectCycle(int[][] graph){
        int n = graph.length;
        
        int[] topOrder = new int[n];
        int[] dfNum = new int[n];
        for(int i=0; i<n; ++i) {
            topOrder[i] = -1;
            dfNum[i] = -1;
        } 
        
        boolean[] cycle = {false};
        int[] currTopOrder = {n};
        int[] currDFNum = {0};
        
        for(int i = 0; i < n && !cycle[0]; ++i){
            DFS(graph, i, topOrder, dfNum, currTopOrder, currDFNum, cycle);
        }
        return cycle[0];
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
