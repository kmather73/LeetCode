struct FreqNode
{
    int value;
    vector<int> indexs;
    
    FreqNode() : value(0)
    {}
    
    bool operator<(const FreqNode &other) const
    {
        if(indexs.size() != other.indexs.size()) return indexs.size() < other.indexs.size();
        
        return indexs.back() < other.indexs.back();
    }
};

class FreqStack {
set<FreqNode> freq;
unordered_map<int, set<FreqNode>::iterator> its;
int size;    
public:
    FreqStack() : size(0){
        
    }
    
    void push(int x) {
        FreqNode node;
        if(its.count(x))
        {
            auto it = its[x];
            node = *it;
            its.erase(x);
        }
        else
        {
            node.value = x;
        }
        
        ++size;
        node.indexs.push_back(size);
        auto it = freq.insert(node).first;
        its[x] = it;
    }
    
    int pop() {
        
        auto it = --freq.end();
        auto node = *it;
        freq.erase(it);
        node.indexs.pop_back();
        if(node.indexs.size())
        {
            freq.insert(node);
            its[node.value] = freq.insert(node).first;
        }
        else
        {
            its.erase(node.value);
        }
        return node.value;
    }
};
