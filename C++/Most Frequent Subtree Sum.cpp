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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> counts;
        countSubtreeSums(root, counts);
        
        int maxCount = 0;
        for(const auto& x :  counts){
            maxCount = std::max(maxCount, x.second);
        }
        
        unordered_set<int> maxSums;
        for(const auto& x :  counts){
            if(x.second == maxCount) maxSums.insert(x.first);
        }
        
        vector<int> l;
        for(const auto& x: maxSums) l.push_back(x);
        return l;
    }
    
    int countSubtreeSums(TreeNode *r, unordered_map<int,int> &counts){
        if(r == nullptr) return 0;
        
        int sum = r->val;
        sum += countSubtreeSums(r->left, counts);
        sum += countSubtreeSums(r->right, counts);
        ++counts[sum];
        
        return sum;
    }
}; 
