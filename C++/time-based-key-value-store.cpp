class TimeMap {
unordered_map<string, map<int, string>> timemap;
    
    public:
    /** Initialize your data structure here. */
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        timemap[key][-timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(!timemap.count(key)) return "";
        
        auto lowerBound = timemap[key].upper_bound(-(timestamp+1));
        if(lowerBound == timemap[key].end()) return "";
        return lowerBound->second;
    }
};
