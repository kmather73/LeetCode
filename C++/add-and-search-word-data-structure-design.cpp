class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct Node
    {
        bool WordEnd;
        unordered_map<char, Node*> suffix;
    };
    
    Node* trie;
    WordDictionary() {
        trie = new Node();
        trie->WordEnd = true;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* t = trie;
        for(char ch : word)
        {
            if(!t->suffix.count(ch))
            {
                t->suffix[ch] = new Node();
            }
            
            t = t->suffix[ch];
        }
        
        t->WordEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return Search(word, 0, trie);
    }
    
    bool Search(string &w, int i, Node* t)
    {
        if(i >= w.size()) return t->WordEnd;
        
        if(w[i] == '.')
        {
            for(auto p : t->suffix)
            {
                if(Search(w, i+1, p.second)) return true;
            }
        }
        else if(t->suffix.count(w[i]))
        {
            return Search(w, i+1, t->suffix[w[i]]);
        }
        
        return false;
    }
};
