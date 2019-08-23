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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        int maximal = 0, level = 0;
        int i = 1;
        while(q.size())
        {
            queue<TreeNode*> tmp;
            int levelSum = 0;
            while(q.size())
            {
                auto t = q.front(); q.pop();
                levelSum += t->val;
                if(t->left) tmp.push(t->left);
                if(t->right) tmp.push(t->right);
            }
            
            if(levelSum > maximal)
            {
                maximal = levelSum;
                level = i;
            }
            ++i;
            swap(tmp, q);
        }
        
        return level;
    }
};
