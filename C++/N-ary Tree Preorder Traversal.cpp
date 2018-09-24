class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> preOrder;
        stack<Node*> s;
        s.push(root);
        
        while(s.size())
        {
            auto top = s.top(); s.pop();
            if(top == nullptr) continue;
            for(auto ir = top->children.rbegin(); ir != top->children.rend(); ++ir)
            {
                s.push(*ir);
            }
            preOrder.push_back(top->val);
        }
        
        return preOrder;
    }
};
