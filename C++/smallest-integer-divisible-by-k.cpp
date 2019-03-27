class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int count = 1, x = 1 % K;
        unordered_set<int> rSeen;
        while(!rSeen.count(x))
        {
            if (x == 0) return count;
            rSeen.insert(x);
            x  = (x*10 + 1) % K;
            ++count;
        }
        
        return -1;
    }
};
