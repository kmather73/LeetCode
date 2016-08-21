class Node2 {
public:
    vector<Node2*> childs;
    int length;
    bool terminal;
    string str;
    Node2(bool t, string s) : length(0), terminal(t), str(s){};
};

class Solution {
public:
    int lengthLongestPath(string input) {
        vector<string> words;
        split(input, '\n', words);
        
        Node2 root(false, "");
        Node2* p = &root;

        for(int i=0; i<words.size(); ++i){
            vector<string> moreWords;
            split(words[i], '\t', moreWords);

            for(int j=1; j < moreWords.size(); ++j){
                p = p->childs.back();
            }
            string word = moreWords.back();
            p->childs.push_back( new Node2( word.find_first_of('.') != std::string::npos, word));
            p = &root;
        }

        bool found=false;
        
        return std::max(0, DFS(&root, found)-1);
        
    }
    
    int DFS(Node2* root, bool& valid){
        cout << root->str << endl;
        int length = 0;
        for(Node2* p: root->childs){
            bool found = false;
            int subPath = DFS(p, found)+root->str.size()+1;
            
            if( found ) length = max(length, subPath);
        }
        
        if(root->terminal){
            length = root->str.size();
        }

        valid = length!=0;
        return length;
    }

    void split(const string &s, char delim, vector<string> &elems) {
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
    }


    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        split(s, delim, elems);
        return elems;
    }
};
