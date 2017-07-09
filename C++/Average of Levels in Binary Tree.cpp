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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> v;
        if(root == nullptr) return v;
        queue<TreeNode*> s1;
        queue<int> s2;
        
        s1.push(root);
        s2.push(0);
        int level = 0;
        while(s1.size()) {
            
            int tmpLev = s2.front();
            
            double avg = 0;
            int count = 0;
            
            while(s2.size() && s2.front() == tmpLev){
                TreeNode* tmp = s1.front(); s1.pop();
                s2.pop();
                if(tmp != nullptr) {
                    s1.push(tmp->left);
                    s1.push(tmp->right);
                    s2.push(tmpLev + 1);
                    s2.push(tmpLev + 1);
                    ++count;
                    avg += tmp->val;
                }
                
            }
            
            if(count != 0)
            v.push_back(avg/count);
        }
        
        return v;
    }
};
