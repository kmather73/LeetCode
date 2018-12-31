class StockSpanner {
struct Node {
    int val;
    int counts;
    
    Node(int p) : val(p), counts(1){}
};
    
public:
    vector<Node*> runs;
    StockSpanner() {}
    
    int next(int price) {
        auto ele = new Node(price);
        for(int i = runs.size()-1; i >= 0; --i)
        {
            if(runs[i]->val <= price) 
            {
                ele->counts += runs[i]->counts;
                runs.pop_back();
            }
            else break;
        }
        runs.push_back(ele);
        return ele->counts;
    }
};
