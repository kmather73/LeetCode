class Solution {
public:
    int countBinarySubstrings(string s) {
        int count = 0, runningBit = s[0] - '0';
        int bits[2] = {0, 0};
        
        for(int i=0; i <s.size(); ++i) {
            int bit = s[i] - '0';
            if(bit != runningBit){
                runningBit = bit;
                count += min(bits[0], bits[1]);
                bits[runningBit] = 0;
            }
            ++bits[bit];
        }
        count += min(bits[0], bits[1]);
        
        return count;
    }
};
