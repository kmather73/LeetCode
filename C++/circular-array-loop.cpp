class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        unordered_set<int> used;
        
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            int dir = nums[i] > 0 ? 1 : -1;
            if(!used.count(i))
            {
                unordered_set<int> cycle;
                int j = i;
                while(dir * nums[j] > 0)
                {
                    if(cycle.count(j)) return true;
                    
                    int next = (n + dir * ((dir * nums[j]) % n) + j) % n;
                    if(next == j) break;
                    
                    cycle.insert(j);
                    used.insert(j);
                    j = next;
                }
            }
        }
        
        return false;
    }
};
