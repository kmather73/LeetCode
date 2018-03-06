class Solution {

    class Compare {
        public:
        bool operator() (vector<int> A, vector<int> B) {
            return !(A[1] < B[1]);
        }
    };
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, unordered_map<int,int>> graph;
        
        for(auto flight : flights)
        {
            graph[flight[0]][flight[1]] = flight[2];
        }
        
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        pq.push({src, 0, 0});
        
        while(pq.size()) 
        {
            auto top = pq.top(); pq.pop();
            if(top[0] == dst) return top[1];
            if(top[2] <= K) 
            {
                for(auto next : graph[top[0]])
                {   
                    pq.push({next.first,
                               next.second + top[1],
                               1 + top[2]});
                }
            }
        }
        return -1;   
    }
};
