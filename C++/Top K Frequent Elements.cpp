class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if( k == nums.size() )
            return nums;
            
        std::unordered_map<int, int> map;
        
        for(int num: nums)
            ++map[num];
        
        
        int n = nums.size()+1;
        std::vector< std::vector<int> >  counts (n);
        
        for(auto ele : map)
            counts[ ele.second ].push_back( ele.first );
        
        
        std::vector<int> topK;
        for(auto vec : counts){
            for(int ele: vec){
                topK.push_back( ele );
                if(topK.size() >= k)
                    return topK;
            }
        }
        
        return topK;
    }
};
