class Solution {
public:
    string reverseStr(string &s, int k) {
        int n = s.size();
        int m = (n+k-1) / k;
        for(int i=0; i < m; ++i){
            if(i%2 == 0) reverse(s, i*k, min(n, (i+1)*k));
        }
        
        return s;
    }
    
    void reverse(string& str, int s, int t){
        for(int i=0; i < (t-s)/2; ++i){
            swap(str[i+s], str[t-1-i]);
        }
    }
};
