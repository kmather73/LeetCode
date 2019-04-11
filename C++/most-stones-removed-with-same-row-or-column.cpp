struct Node
{
    Node(int a, int b, int c) : x(a), y(b), w(c) {}
    Node() : Node(0, 0, 1) {}
    Node(const Node &n) 
    {
        x = n.x, y = n.y, w = n.w;
    }
    
    int x;
    int y;
    int w;
    
    bool operator==(const Node &o) const
    {
        return x == o.x && y == o.y;
    }
    
    const Node operator=(const Node &o)
    {
        x = o.x;
        y = o.y;
        w = o.w;
        return o;
    }
};

namespace std
{
template <>
struct hash<Node>
    {
        size_t operator()(const Node& n) const
        {
            return hash<int>()(n.x) ^ (hash<int>()(n.y) << 1);
        }
    };
}

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<Node, Node> UF;
        unordered_map<int, vector<Node>> rows;
        unordered_map<int, vector<Node>> cols;
        
        for(auto s : stones)
        {
            Node n(s[0], s[1], 1);
            UF[n] = n;
            if(rows[s[0]].size() == 0) rows[s[0]].push_back(n);
            if(cols[s[1]].size() == 0) cols[s[1]].push_back(n);
            
            Union(UF, rows[s[0]][0], n);
            Union(UF, cols[s[1]][0], n);
        }
        
        unordered_set<Node> counts;
        int count = 0;
        for(auto p : UF)
        {
            auto pp = Find(UF, p.first);
            if(pp == p.first) count += pp.w - 1;
        }
        
        return count;
    }
       
    Node& Find(unordered_map<Node, Node> &UF, Node n)
    {
        while(!(UF[n] == n))
        {
            UF[n] = UF[UF[n]];
            n = UF[n];
        }
        
        return UF[n];
    }
      
    void Union(unordered_map<Node, Node> &UF, Node a, Node b)
    {
        auto pa = Find(UF, a);
        auto pb = Find(UF, b);
        
        if(!(pa == pb))
        {
            if(pa.w < pb.w) swap(a, b);
            
            UF[pb] = pa;
            UF[pa].w += pb.w;
        }
    }
};
