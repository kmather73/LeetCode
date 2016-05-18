class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int, int> elements;
        
        for(int n : nums1)
            elements[ n ]++;
            
        std::vector<int> intersection;
        
        for(int n : nums2){
            if(elements[ n ] > 0)
                intersection.push_back( n );
            elements[ n ] = 0;
        }
            
        return intersection;
    }
};
