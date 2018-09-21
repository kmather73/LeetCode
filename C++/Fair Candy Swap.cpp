class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int candyA=0, candyB = 0;
        unordered_set<int> setA;
        for(int a: A) 
        {
            candyA += a;
            setA.insert(a);
        }
        
        for(int b: B) candyB += b;
        auto diff = (candyA - candyB) / 2;
        
        
      
        for(int b : B)
        {
            if(setA.count(b + diff)) return {b+diff, b};
        }
    }
};
