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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == nullptr && t == nullptr) return true;
        if(t == nullptr) return true;
        if(s == nullptr) return false;
        
        return sameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    
    bool sameTree(TreeNode* s, TreeNode* t){
        if(s == nullptr && t == nullptr) return true;
        if(s == nullptr || t == nullptr) return false;
        if(s->val != t->val) return false;
        
        return sameTree(s->left, t->left) && sameTree(s->right, t->right);
    }
    
};
