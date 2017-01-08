class Solution {
public:
    int magicalString(int n) {
        if(n <= 1) return n;
        
        vector<int> s{0,1,2,2};
        int count = 1, i = 3;
        while(s.size() <= n){
            count += min(s[i]*(1+(i+1)%2  == 1), (int)(1+n-s.size()));
            for(int j=0;j<s[i] && s.size() <= n; ++j){
              s.push_back(1+(i+1)%2);
            }
            ++i;
        }
        return count;
    }
};
