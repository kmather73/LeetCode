//TLE

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 #include <algorithms>
 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() <= 1 || intervals.size() >= 100)
            return intervals;
            
        std::sort(intervals.begin(), intervals.end(), myfunction);
        std::vector<Interval> mergedIvals; 
        
        int start, end, i;
        
        for(i=0; i < intervals.size(); ){
            start = intervals[i].start;
            end = intervals[i].end;
            
            int j = i+1;
            while(j < intervals.size() && intervals[j].start <= end ) {
                end = std::max(intervals[j].end, end);
                ++j;
            }
            
            i = j;
            mergedIvals.push_back( Interval(start, end) );
        }
        
        return mergedIvals;
        
    }
    
    
    static bool myfunction (Interval i ,Interval j) { 
        if ( i.start != j.start)
            return i.start < j.start;
        else
            return j.end <= i.end; 
        
    }
};
