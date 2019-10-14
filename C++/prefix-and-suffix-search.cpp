struct Node
{
    unordered_map<char, Node*> nodes;
    unordered_set<int> wordParts;
};

class Trie 
{    
    Node* root;
    int size;
    
public:
    Trie() : size(0)
    {
        root = new Node();
    }
    
    void AddWord(string &word, bool rev)
    {
        Node* r = root;
        int i = rev ? word.size() - 1 : 0;
        int delta = rev ? -1 : 1; 
        
        while( i >= 0 && i < word.size())
        {
            if(!r->nodes.count(word[i]))
            {
                r->nodes[word[i]] = new Node();
            }
            
            r->wordParts.insert(size);
            r = r->nodes[word[i]];
            
            i += delta;
        }
        
        r->wordParts.insert(size);
        ++size;
    }
    
    unordered_set<int> PossibleWords(string & s, bool rev)
    {
        Node* r = root;
        int i = rev ? s.size() - 1 : 0;
        int delta = rev ? -1 : 1; 
        
        while( i >= 0 && i < s.size() && r != nullptr)
        {
            r = r->nodes[s[i]];
            i += delta;
        }
        
        return r == nullptr ? unordered_set<int>() : r->wordParts;
    }
};

class WordFilter {
Trie Prefix;
Trie Suffix;
unordered_map<string, unordered_set<int>> memoPre;
unordered_map<string, unordered_set<int>> memoSuf;
unordered_map<string, unordered_map<string, int>> memo;

public:
    WordFilter(vector<string>& words) {
        for(auto word : words)
        {
            Prefix.AddWord(word, false);
            Suffix.AddWord(word, true);
        }
    }
    
    int f(string prefix, string suffix) {
        if(memo.count(prefix) && memo[prefix].count(suffix)) return memo[prefix][suffix];
        
        auto s1 = GetPre(prefix);
        auto s2 = GetSuf(suffix);
        
        int weight = -1;
        if(s1.size() > s2.size()) swap(s1, s2);
        
        for(auto x : s1)
        {
            if(s2.count(x)) weight = max(weight, x);
        }
        
        return memo[prefix][suffix] = weight;
    }
    
    unordered_set<int> GetPre(string &prefix)
    {
        if(memoPre.count(prefix)) return memoPre[prefix];
        
        return memoPre[prefix] = Prefix.PossibleWords(prefix, false);
    }
    
    unordered_set<int> GetSuf(string &suffix)
    {
        if(memoSuf.count(suffix)) return memoSuf[suffix];
        
        return memoSuf[suffix] = Suffix.PossibleWords(suffix, true);
    }
};
