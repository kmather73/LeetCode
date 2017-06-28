class Solution {
public:

    string getNext(string s){
        string str = "";
        int i=0, n = s.size();
        
        while(i < n) {
            int count = 1;
            ++i;
            
            while(i < n && s[i-1] == s[i]){
                ++i;
                ++count;
            }
            str += to_string(count) + s[i-1];
        }
        
        return str;
    }
    
    string countAndSay(int n) {
        string str = "1";
        for(int i=1; i < n; ++i) {
            str = getNext(str);
        }
        
        return str;
    }
};
