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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> counts;
        int max = 0;
        utill(root, counts, max);
        
        vector<int> modes;
        
        for(auto& y : counts){
            if(y.second == max){
                modes.push_back(y.first);
            }
        }
        return modes;
    }
    
    void utill(TreeNode* r, unordered_map<int,int> &counts, int &max){
        if(r == nullptr) return;
        
        ++counts[r->val];
        max = std::max(max, counts[r->val]);
        utill(r->left, counts, max);
        utill(r->right, counts, max);
    }
    
};
