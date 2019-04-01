class Solution {
public:
    string baseNeg2(int N) {
        if(N == 0) return "0";
        string str;
        int p = 1;
        while(N)
        {
            
            auto r = N % 2;
            str.push_back('0'+r);
            N = (N - p * r) / 2;
            p *= -1;
        }
        
        reverse(str.begin(), str.end());
        return str;
    }
};
