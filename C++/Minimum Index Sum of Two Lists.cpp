class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;
        vector<string> results;
        
        int min = INT_MAX;
        
        for (int i=0; i<list1.size(); ++i) {
            mp[list1[i]] = i;
        }
        
        for (int j=0; j<list2.size(); ++j) {
            if (mp.count(list2[j])) {
                int indexSum = mp[list2[j]] + j;
                if (indexSum < min) {
                    min = indexSum;
                    results.clear();
                }
                
                if(indexSum == min){
                    results.push_back(list2[j]);
                }
            }
        }
        
        return results;
    }
};
