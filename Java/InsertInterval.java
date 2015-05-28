/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        List<Interval> CollectionOfMergedIntervals = new ArrayList<Interval>();
        
        if(intervals == null || intervals.size() == 0){//Edge case we have nothing to merge with.
            CollectionOfMergedIntervals.add(newInterval);
            return CollectionOfMergedIntervals;
        }
        
        boolean mergedNewIntervalYet = false;//flag to know when we have merged the intervals.
        
        for(Interval currentInterval : intervals){
            if(currentInterval.end < newInterval.start){//The current interval is completely before the new interval so add it to the list
                CollectionOfMergedIntervals.add(currentInterval);
            }
            else if(currentInterval.start > newInterval.end){//The current interval is completely after the new interval.
                if(!mergedNewIntervalYet){// Add the newinterval joined with any overplaing intervals to the list.
                    mergedNewIntervalYet = true;//Remeber not to add it multiple times
                    CollectionOfMergedIntervals.add(newInterval);
                }
                CollectionOfMergedIntervals.add(currentInterval);
            }
            else{//The current interval and the new interval overlap
                newInterval.start = Math.min(newInterval.start, currentInterval.start);// update the staring point.
                newInterval.end = Math.max(newInterval.end, currentInterval.end);//update the ending point.
            }
        }
        if(!mergedNewIntervalYet)//Merge the overplaing intervals and then add to the list if still needed.
            CollectionOfMergedIntervals.add(newInterval);
        return CollectionOfMergedIntervals;
    }
}
