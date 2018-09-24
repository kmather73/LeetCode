class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> postOrder;
        if(root == nullptr) return postOrder;
        
        stack<pair<Node*, int>> s;
        s.push(make_pair(root, 0));
        Node *prev = nullptr;
        
        while(s.size())
        {
            auto top = s.top();
            auto node = top.first;
            auto idx = top.second;
            
            if(idx >= node->children.size())
            {
                s.pop();
                postOrder.push_back(node->val);
            }
            else
            {
                if(node->children[idx] == prev) 
                {
                    s.pop();
                    s.push(make_pair(node, idx+1));
                }
                else s.push(make_pair(node->children[idx], 0));
            }
            
            prev = node;
        }
        
        return postOrder;
    }
};
