struct Node
{
    unordered_map<string, Node*> subfolders;
    bool leaf;
};

class Trie
{
    Node* r;
public:
    Trie()
    {
        r = new Node();
    }
    
    void Insert(string &folder)
    {
        istringstream iss(folder);
        string item;
        auto rr = r;
        getline(iss, item, '/');
        while (getline(iss, item, '/')) 
        {
            if(rr->leaf)
            {
                break;
            }
            
            if (rr->subfolders.count(item))
            {
            }
            else
            {
                rr->subfolders[item] = new Node();
            }
            
            rr = rr->subfolders[item];
            
        }
        
        rr->leaf = true;
    }
    
    vector<string> GetTopFolders()
    {
        vector<string> strs;
        string root = "";
        GetTopFolders(root, r, strs);
        return strs;
    }
    
    void GetTopFolders(string &path, Node* r, vector<string> &f)
    {
        if (r != nullptr && !r->leaf)
        {
            path.push_back('/');
            auto len = path.size();
            for (auto p : r->subfolders)
            {    
                path += p.first;
                if(p.second->leaf)
                {
                    f.push_back(path);
                }
                else
                {
                    GetTopFolders(path, p.second, f);
                }
                path.erase(len);
            }
            path.pop_back();
        }
    }
};

class Solution {
Trie tree;
    public:
    vector<string> removeSubfolders(vector<string>& folders) {
        for(auto folder : folders) tree.Insert(folder);
        
        return tree.GetTopFolders();
    }
};
