class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        auto cmp =  [](const Interval &a, const Interval &b)
             {
                return a.end < b.end;
             };
        
        sort(A.begin(), A.end(), cmp);        
        sort(B.begin(), B.end(), cmp);
        
        int i=0, j=0;
        int n = A.size(), m = B.size();
        
        vector<Interval> intersect;
        while(i < n && j < m)
        {
            if(B[j].start <= A[i].end && A[i].end <= B[j].end)
            {
                intersect.push_back(GetOverlap(A[i], B[j]));
                ++i;
            }
            else if(A[i].start <= B[j].end && B[j].end <= A[i].end)
            {
                intersect.push_back(GetOverlap(A[i], B[j]));
                ++j;
            }
            else if(A[i].end < B[j].start) ++i;
            else ++j;
        }
        
        return intersect;
    }
    
    inline Interval GetOverlap(const Interval& A, const Interval& B)
    {
        auto start = max(A.start, B.start);
        auto end = min(A.end, B.end);
        return Interval(start, end);
    }
};
