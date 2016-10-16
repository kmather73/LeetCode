class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> used;
        std::priority_queue<int, std::vector<int>, std::less<int>> q;
        vector<int> maxThree(3, INT_MIN);
        
        for(auto& x: nums){
            if(used.count(x) == 0){
                int i=0; 
                while(i<3 && x > maxThree[i]) ++i;
                
                maxThree.insert(maxThree.begin()+i, x);
                maxThree.erase(maxThree.begin());
                used.insert(x);
                
                q.push(x);
                if(q.size() > 3) q.pop();
            }
        }
        
        int max;
        if(q.size() < 3) max = q.top();
        else max = maxThree[0];
        
        return max;
    }
};
