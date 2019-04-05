class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_set<char> used;
        unordered_map<int, int> lastPos;
        vector<int> parts;
        
        int n = S.size();
        for(int i=0; i < n; ++i) lastPos[S[i]] = i;
        
        int i=0;
        while(i < n)
        {
            auto start = i;
            auto last = lastPos[S[i]];
            while(i < last) 
            {
                used.insert(S[i]);
                last = max(last, lastPos[S[i]]);
                ++i;
            }
            parts.push_back(last - start + 1);
            i = last + 1;
        }
        
        return parts;
    }
};
