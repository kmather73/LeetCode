class LogSystem {
    map<string, int> mp;
    
public:
    LogSystem() {}
    
    void put(int id, string timestamp) {
        mp[timestamp] = id;   
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        vector<int> v;
        
        s = getDate(s, gra);
        e = getDate(e, gra);
        auto it =  mp.lower_bound(s);
        while(it != mp.end()) {
            const string date = getDate(it->first, gra); 
            
            if(date > e) break;
            
             v.push_back( it->second );
            ++it;
        }
        
        return v;
    }
    
    string getDate(const string &str, string &gra) {
        if(gra == "Year") return str.substr(0, 4);
        else if(gra == "Month") return str.substr(0, 7);
        else if(gra == "Day") return str.substr(0, 10);
        else if(gra == "Hour") return str.substr(0, 13);
        else if(gra == "Minute") return str.substr(0, 16);
        return str;
    }
};
