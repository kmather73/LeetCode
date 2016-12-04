class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> maxRuns(26, 0);
        
        int currRun = 0;
        for(int i=0; i < p.size(); ++i){
            if( i > 0 && (p[i]-p[i-1] == 1  || p[i-1]-p[i] == 25)) ++currRun;
            else currRun = 1;
            
            int idx = p[i]-'a';
            maxRuns[idx] = max(maxRuns[idx], currRun);
        }
        
        return accumulate(maxRuns.begin(), maxRuns.end(), 0);
    }
};
