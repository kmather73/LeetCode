class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool Alt = true;
        int lastBit = !(n%2);
        while(n) {
            int bit = n%2;
            n /= 2;
            
            if(bit == lastBit) return false;
            lastBit = bit;
        }
        
        return true;
    }
};
