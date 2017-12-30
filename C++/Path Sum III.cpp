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
    int pathSum(TreeNode* root, int sum, int acc=0) {
        int count = 0;
        queue<TreeNode*> Q;
        Q.push(root);
        
        while(Q.size()){
            auto r = Q.front(); Q.pop();
            if(r){
                DFS_SUM(r, sum, count);
                Q.push(r->left);
                Q.push(r->right);
            }
        }
        return count;
    }
    
    void DFS_SUM(TreeNode* r, int sum, int &count){
        if(r == nullptr) return;
        sum -= r->val;
        if(sum == 0) ++count;
        
        DFS_SUM(r->left, sum, count);
        DFS_SUM(r->right, sum, count);
    }
};
