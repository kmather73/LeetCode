class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0, j =0;
        
        while(i < bits.size())
        {
            j = i;
            if(bits[i] == 0) ++i;
            else i += 2;
        }
        
        return j+1 == i;
    }
};
