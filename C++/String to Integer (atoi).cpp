class Solution {
public:
    int myAtoi(const string &str) {
        if(str.size() == 0) return 0;
        
        stringstream ss(str);
        int x;
        ss >> x;
        return x;
    }
};
