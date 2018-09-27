class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> change;
        
        for(auto bill : bills)
        {
            if(bill == 5) ++change[5];
            else if(bill == 10)
            {
                if(change[5] == 0) return false;
                --change[5];
                ++change[10];
            }
            else if(bill == 20)
            {
                
                if(change[5] == 0) return false;
                
                if(change[10] > 0)
                {
                    --change[5];
                    --change[10];
                }
                else if(change[5] < 3) return false;
                else change[5] -= 3;
            }
        }
        return true;
    }
};
