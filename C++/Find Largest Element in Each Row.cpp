/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> findValueMostElement(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> q;
        queue<int> level;
        
        q.push(root);
        level.push(0);
        vector<int> mac;
        
        int m=-1;
        while(q.size()){
            TreeNode *r = q.front(); q.pop();
            int l = level.front(); level.pop();
            if(r->left) {
                q.push(r->left);
                level.push(l+1);
            }
            
            if(r->right){
                q.push(r->right);
                level.push(l+1);
            }
            
            if(l > m){
                m = l;
                mac.push_back(r->val);
            } else {
                mac[l] = std::max(mac[l], r->val);
            }
        }
        
        return mac;
    }
};
