class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> map;
        for(auto& num : nums) ++map[num];
        
        
        vector<int> dups;
        for(auto& pair: map){
            if(pair.second == 2) dups.push_back( pair.first );
        }
        
        return dups;
    }
};
