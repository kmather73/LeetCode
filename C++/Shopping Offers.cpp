class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return utill(price, special, needs, 0);
        
    }
    
    long int utill(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int s) {
        
        if(s >= special.size()) {
            int cost = 0;
            for(int i=0; i < needs.size(); ++i) cost += price[i]*needs[i];
            
            return cost;
        }
        
        long unused = utill(price, special, needs, s+1);
        bool valid = true;
        for(int i = 0; i < needs.size(); ++i)  {
            needs[i] -= special[s][i];
            valid = valid && needs[i] >= 0;
        }
        long used = INT_MAX;;
        if(valid) {
            used = special[s].back() + utill(price, special, needs, s);
        }
        for(int i = 0; i < needs.size(); ++i)  {
            needs[i] += special[s][i];
        }
        
        return min(used, unused);
    }
};
