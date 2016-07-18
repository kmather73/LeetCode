/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "#";
        
        std::queue<TreeNode*> Q;
        Q.push(root);
        std::string treeString;
        
        while(Q.size() > 0){
            TreeNode* temp = Q.front();
            Q.pop();
            
            if(temp != nullptr){
                treeString +=  to_string(temp->val) + ",";
                Q.push(temp->left);
                Q.push(temp->right);
            } else
                treeString += "#,";
        }
        treeString.pop_back();
        return treeString;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> tree = split(data);
        
        queue<TreeNode*> Q;
        Q.push(tree[0]);
        
        int i = 0;
        while(Q.size() > 0){
            TreeNode* node = Q.front(); Q.pop();
            
            if(i+1 < tree.size()) node->left = tree[i+1];
            if(i+2 < tree.size()) node->right = tree[i+2];
            i += 2;
            
            if(node && node->left) Q.push(node->left);
            if(node && node->right) Q.push(node->right);
        }
        
        return tree[0];
    }

private:    
    vector<TreeNode*> &split(const string &s, vector<TreeNode*> &elems, char delim=',') {
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            TreeNode* newNode = nullptr;
            if (item != "#") {
                int val = stoi(item);
                newNode = new TreeNode(val);
            }
            elems.push_back(newNode);
        }
        return elems;
    }

    vector<TreeNode*> split(const string &s) {
        vector<TreeNode*> elems;
        split(s, elems);
        return elems;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
