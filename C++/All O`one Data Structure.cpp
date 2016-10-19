class AllOne {
private:
    unordered_map<string, int> map;
    unordered_map<int, tuple<int, int, set<string>>> counts;
    tuple<int, int, set<string>> *max, *min;
    
    void deleteNode(int n){
        if(counts.count(n) == 0 || n == 0 || n == INT_MAX) return;
        
        auto& tup = counts[n];
        int left = get<0>(tup);
        int right = get<1>(tup);
        
        auto& leftTup = counts[left];
        auto& rightTup = counts[right];
        
        get<1>(leftTup) = right;
        get<0>(rightTup) = left;
    }
    
    void createRightNode(int n){
        if(get<2>(counts[n+1]).size() > 0 || (get<2>(counts[n]).size() == 0 && n != 0)) return;
        
        int right = get<1>(counts[n]);
        auto& rightTup = counts[right];
        
        auto& leftTup = counts[n];
        auto& newTup = counts[n+1];
        
        get<1>(leftTup) = n+1;
        get<0>(newTup) = n;
        get<1>(newTup) = right;
        get<0>(rightTup) = n+1;
    }
    
    void createLeftNode(int n){
        if(n <= 0 || (n!= INT_MAX && get<2>(counts[n]).size() == 0) || get<2>(counts[n-1]).size() > 0 ) return;
        
        int left = get<0>(counts[n]);
        auto &leftTup = counts[left];
        auto &newTup = counts[n-1];
        
        get<1>(newTup) = n;
        get<0>(newTup) = left;
        get<0>(counts[n]) = n-1;
        get<1>(leftTup) = n-1;
    }
    
public:
    /** Initialize your data structure here. */
    AllOne() {
        min = &counts[0];
        max = &counts[INT_MAX];
        get<1>(*min) = INT_MAX;
        get<0>(*max) = 0;
        get<1>(*max) = INT_MAX;
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        int oldCount = map[key];
        int newCount = ++map[key];
        
        auto& newTup = counts[newCount];
        auto& oldTup = counts[oldCount];
        
        createRightNode(oldCount);
        get<2>(newTup).insert(key);
        get<2>(oldTup).erase(key);
        
        if(get<2>(oldTup).size() == 0 ) deleteNode(oldCount);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(map[key] == 0) return;
        
        int oldCount = map[key];
        int newCount = --map[key];
        
        auto& oldTup = counts[oldCount];
        auto& newTup = counts[newCount];
        
        createLeftNode(oldCount);
        get<2>(newTup).insert(key);
        get<2>(oldTup).erase(key);
        
        if(get<2>(oldTup).size() == 0 ) deleteNode(oldCount);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        auto &maxTup = counts[get<0>(*max)];
        
        return get<2>(maxTup).size() == 0? "" : *get<2>(maxTup).begin();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        auto& minTup = counts[get<1>(*min)];

        return get<2>(minTup).size() == 0? "" : *get<2>(minTup).begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
