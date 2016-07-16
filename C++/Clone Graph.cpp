/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr) return nullptr;
        
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
        queue<UndirectedGraphNode*> bfs;
        
        bfs.push(node);
        while(bfs.size()) { //Copy Nodes
            auto nextNode = bfs.front(); bfs.pop();
            map[nextNode] = new UndirectedGraphNode( nextNode->label );
            
            for(auto vertex: nextNode->neighbors){
                if(map.count(vertex) == 0){
                    bfs.push(vertex);
                }
            }
        }
        
        //Add Edges
        for(auto pair : map){
            for(auto adj : pair.first->neighbors){
                pair.second->neighbors.push_back( map[adj] );
            }
        }
        
        return map[node];
    }
};
