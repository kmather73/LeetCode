class Solution {
public:
    vector<int> build(const string &s){
        int i = s.size()-1;
        int j = 0;
            
        int t1 = 0, t2 = 0, pow = 1;
        while(s[i] != ':') {
            t1 = t1 + pow*(s[i]-'0');
            pow *= 10;
            --i;
            
        }
        
        while(s[j] != ':') {
            t2 = 10*t2 + s[j]-'0';
            ++j;
        }
        
        int start = s[j+1] == 'e';
        return {t2, start, t1};
    }
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> times(n); 
        unordered_map<int,int> mp;
        int running = -1;
        stack<int> paused;
        
        for(const string &s: logs){
            vector<int> v = build(s);
            if(v[1] == 1){ // finished job;
                times[v[0]] += v[2] - mp[v[0]] + 1;
                if(paused.size()){
                    running = paused.top(); paused.pop();
                    mp[running] = v[2] + 1;
                } else {
                    running = -1;
                }
                    
            } else { // start job
                if(running >= 0){
                    paused.push(running);
                    times[running] += v[2] - mp[running];
                }
                    
                running = v[0];
                mp[running] = v[2];
            }
        }
        
        return times;
    }
};
