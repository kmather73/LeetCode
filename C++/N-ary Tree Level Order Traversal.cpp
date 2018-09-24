class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> order;
        if(root) DFS(root, order, 0);
        return order;
    }
    
    void DFS(Node* root, vector<vector<int>> &order, int k)
    {
        if(order.size() <= k) order.push_back(vector<int>(0));
        order[k].push_back(root->val);
        
        for(auto c : root->children) DFS(c, order, k+1);
    }
};
