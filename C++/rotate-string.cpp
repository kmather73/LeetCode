class Solution {
public:
    bool rotateString(string A, string B) {
        auto AA = A + A;
        return A.size() == B.size() && AA.find(B) != string::npos;
    }
};
