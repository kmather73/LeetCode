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
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> mp;
        return find(root, k, mp);   
    }
    
    bool find(TreeNode* r, int k, unordered_map<int,int> &mp){
        if(r==nullptr) return false;
        if(mp.count(k- r->val)) return true;
        
        mp[r->val]=0;
        return find(r->left, k, mp) || find(r->right, k, mp);
    }
};
