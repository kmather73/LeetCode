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
    bool checkEqualTree(TreeNode* root) {
        if(root == nullptr) return false;
        if((root->left == nullptr) && (root->right == nullptr)) return false;
        
        unordered_map<TreeNode*, long long int> treeSums;
        long long int totalSum = sumTree(root, treeSums);
        if(totalSum%2 == 1LL) return false;
        bool canPartition = false;
        
        preorder(root, treeSums, totalSum, canPartition);
        
        return canPartition;
    }
    
    void preorder(TreeNode* r, unordered_map<TreeNode*, long long int> &treeSums, const long long int totalSum, bool &canPartition){
        if(r == nullptr || canPartition) return ;
        
        if(totalSum ==  2*treeSums[r]) canPartition = true;
        
        preorder(r->left, treeSums, totalSum, canPartition);
        preorder(r->right, treeSums, totalSum, canPartition);
    }
    
    long long int sumTree(TreeNode* r, unordered_map<TreeNode*, long long int> &treeSums){
        if(r == nullptr) return 0LL;
        
        treeSums[r] = sumTree(r->left, treeSums) + sumTree(r->right, treeSums) + r->val; 
        return treeSums[r];
    }
};
