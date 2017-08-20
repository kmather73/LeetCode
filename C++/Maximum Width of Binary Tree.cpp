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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        
        queue<TreeNode*> q;
        queue<int> p;
        
        
        int m = 1;
        q.push(root);
        p.push(0);
        int level = 1;
        
        while(q.size()) {
            int count = 0;
            int nullrun = 0;
            int r = INT_MIN, l = INT_MAX;
            
            
            while(level){
                --level;
                TreeNode* rr = q.front(); q.pop();
                int x = p.front(); p.pop();
                
                r = max(r, x);
                l = min(l, x);
                if(rr->left){
                    q.push(rr->left);
                    p.push(2*x);
                    ++count;
                }
                
                if(rr->right){
                    q.push(rr->right);
                    p.push(2*x + 1);
                    ++count;
                }
            }
            
            level = count;
            m = max(m, r-l+1);
        }
        return m;   
    }
};
