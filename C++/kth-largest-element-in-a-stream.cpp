class KthLargest {
public:
    priority_queue<int> q;
    int K;
    KthLargest(int k, vector<int> nums) {
        q = priority_queue<int>(less<int>());
        K = k;
        for(auto num : nums)
        {
            add(num);
        }
    }
    
    int add(int val) {
        q.push(-val);
        if(q.size() > K) q.pop();

        return -q.top();
    }
};
