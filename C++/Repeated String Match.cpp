class Solution {
public:
    int repeatedStringMatch(string &A, string &B) {
        int i=1;
        string c = A;
        while(c.size() < B.size()){
            c += A;
            ++i;
        }
        
        for(int j=0; j <= 2; ++j){
            if(c.find(B) != string::npos) return i;
            c += A;
            ++i;
        }
        
        return -1;
    }
};
