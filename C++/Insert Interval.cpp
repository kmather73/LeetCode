/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        std::vector<Interval> mergedIvals;
        int i=0;
        
        
        //Get all the intervals that are nonover lapping to the left
        while(i < intervals.size() && intervals[i].end < newInterval.start)
            mergedIvals.push_back( intervals[i++] );
    
    
        //Currently merging new inteval wiht all overlapping ones
        if( i < intervals.size())
            newInterval.start = std::min(newInterval.start, intervals[i].start);
        
        while(i < intervals.size() && intervals[i].start <= newInterval.end )
            newInterval.end = std::max(newInterval.end, intervals[i++].end);
        
        mergedIvals.push_back(newInterval);
        //Done adding/merging new interval
        
        
        //Get all the intervals that are nonover lapping to the right
        while(i < intervals.size() )
            mergedIvals.push_back( intervals[i++] );
            
        return mergedIvals;
    }
};
