class Solution {
public:
    int findComplement(int num) {
        return ~num & ((1 <<(int)log2(num))-1);
    }
};
