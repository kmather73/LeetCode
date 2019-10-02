class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> pairs;
        int minDist = INT_MAX;
        for(int i=1; i < arr.size(); ++i)
        {
            auto dist = arr[i] - arr[i-1];
            if(dist < minDist)
            {
                minDist = dist;
                pairs.clear();
            }
            
            if(dist == minDist)
            {
                pairs.push_back({arr[i-1], arr[i]});
            }
        }
        
        return pairs;
    }
};
