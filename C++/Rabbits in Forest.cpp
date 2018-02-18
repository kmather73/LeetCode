class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> counts;
        
        for(auto x : answers)
        {
            ++counts[x];
        }
        
        int minCount = 0;
        for(auto pair : counts)
        {
            int count = pair.second;
            int val = pair.first;
           
            minCount += (val+1) * ((count+val)/(val+1));
        }
        
        return minCount;
    }
};
