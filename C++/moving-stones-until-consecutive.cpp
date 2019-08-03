class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> v{a, b, c};
        sort(v.begin(), v.end());
        a = v[0], b = v[1], c = v[2];
        if(a + 2 == c) return {0, 0};
        return {min(c-b, b-a) <= 2? 1 : 2, c - a - 2};   
    }
};
