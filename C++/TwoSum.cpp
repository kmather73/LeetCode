#include <unordered_map>
#include <algorithm>
#include<vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> map{};
        int count{0};
        for(auto num : nums){
            ++count;
            if(map.find(num) != map.end()){
                vector<int> sol{count,map[num]};
                std::sort( sol.begin(), sol.end() );
                return sol;
            }
            map.insert( {target-num, count});
        }
    }
};
