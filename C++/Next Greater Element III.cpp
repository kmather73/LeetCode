class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        
        if (next_permutation(s.begin(), s.end())) {
            long x = std::stol(s);
            if(x == (x&0x7FFFFFFF)) return (int)x;
        }
        return -1;
    }
};
