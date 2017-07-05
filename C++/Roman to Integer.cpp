class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> lookupTbl {
            {"", 0},
            {"I", 1},
            {"II", 2},
            {"III", 3},
            {"IV", 4},
            {"V", 5},
            {"VI", 6},
            {"VII", 7},
            {"VIII", 8},
            {"IX", 9},
            {"X", 10},
            {"XX", 20},
            {"XXX", 30},
            {"XL", 40},
            {"L", 50},
            {"XC", 90},
            {"C", 100},
            {"CD", 400},
            {"D", 500},
            {"CM", 900},
            {"M", 1000}
        };

        int val=0;
        int i=0; 

        while(i < s.size()){
            string str = "" ;
            while(i<s.size() && lookupTbl.count(str+s[i]) > 0) {
                str = str + s[i];
                ++i;
            }

            int value = lookupTbl[str];
            val += value;
        }


        return val;
    }
};
