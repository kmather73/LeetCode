class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int len = 0;
        sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b){
           return a[1] < b[1];
        });
        
        
        int end = INT_MIN;
        if(pairs.size() > 0 && pairs[0][1] == end) ++len;
        
        for(int i=0; i < pairs.size(); ++i) {
            if(pairs[i][0] > end){
                ++len;
                end = pairs[i][1];
            }
        }
        
        return len;
    }
};
