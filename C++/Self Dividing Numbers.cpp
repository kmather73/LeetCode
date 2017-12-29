class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> list;
        
        for(int i = left; i <= right; ++i){
            if(selfDiv(i)) list.push_back(i);
        }
        return list;
    }
    
    bool selfDiv(int x)
    {
        int y = x;
        bool div = true;
        while(div && y)
        {
            int digit = y%10;    
            y = y/10;
            div =  digit != 0 && 0 == x % digit;
        }
        
        return div;
    }
};
