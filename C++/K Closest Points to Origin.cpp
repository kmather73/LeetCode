class mycomparison {
public:
  mycomparison(){}
  bool operator() (const vector<int>& lhs, const vector<int>& rhs) const
  {
    return lhs[0]*lhs[0] + lhs[1]*lhs[1] < rhs[0]*rhs[0] + rhs[1]*rhs[1];
  }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>,vector<vector<int>>,mycomparison> pq;
        
        for(auto &x : points)
        {
            pq.push(x);
            if(pq.size() > K) pq.pop();
        }
        
        vector<vector<int>> kpoints;
        while(pq.size()) 
        {
            kpoints.push_back(pq.top());
            pq.pop();
        }
        
        return kpoints;
    }
};
