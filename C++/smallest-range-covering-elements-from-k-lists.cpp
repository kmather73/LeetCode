class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> v(2, 0);
        int k = nums.size();
        int minD = INT_MAX;
        vector<int> offset(k, 0);
        
        auto cmp = [&](const int &a, const int &b)
        {
            return nums[a][offset[a]] > nums[b][offset[b]];  
        };
        
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        int end = 0;
        for(int i = 0; i < k; ++i)
        {
            q.push(i);
            end = max(end, nums[i][0]);
        }
        
        while(q.size() == k)
        {
            auto top = q.top(); q.pop();
            int start = nums[top][offset[top]];
            int d = end - start;
            
            if(d < minD)
            {
                v[0] = start;
                v[1] = end;
                minD = d;
            }
            
            ++offset[top];
            if(offset[top] < nums[top].size())
            {
                q.push(top);
                end = max(end, nums[top][offset[top]]);
            }
        }
        
        return v;
    }
};
