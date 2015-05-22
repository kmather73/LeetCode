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
        List<Interval> merged = new ArrayList<Interval>();
        if(intervals == null || intervals.size() == 0){
            merged.add(newInterval);
            return merged;
        }
        
        boolean flag = false;//flag to now when we have merged the intervals.
        
        for(Interval currInt : intervals){
            if(currInt.end < newInterval.start){//The current interval is completely before the new interval so add to the list.
                merged.add(currInt);
            }
            else if(currInt.start > newInterval.end){//The current interval is completely after the new interval.
                if(!flag){// Merge the overplaing intervals and then add to the list.
                    flag = true;
                    merged.add(newInterval);
                }
                merged.add(currInt);
            }
            else{//The current interval and the new interval overlap
                newInterval.start = Math.min(newInterval.start, currInt.start);// update the staring point.
                newInterval.end = Math.max(newInterval.end, currInt.end);//update the ending point.
            }
        }
        if(!flag)//Merge the overplaing intervals and then add to the list if still needed.
            merged.add(newInterval);
        return merged;
    }
}



//Cleaner version but less optimized
public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        List<Interval> merged = new ArrayList<Interval>();
        if(intervals == null || intervals.size() == 0){
            merged.add(newInterval);
            return merged;
        }
        
        int insertPos = 0;

        for(Interval currInt : intervals){
            if(currInt.end < newInterval.start){//The current interval is completely before the new interval so add to the list.
                merged.add(currInt);
                ++insertPos;
            }
            else if(currInt.start > newInterval.end){//The current interval is completely after the new interval.
                merged.add(currInt);
            }
            else{//The current interval and the new interval overlap
                newInterval.start = Math.min(newInterval.start, currInt.start);// update the staring point.
                newInterval.end = Math.max(newInterval.end, currInt.end);//update the ending point.
            }
        }
        merged.add(insertPos,newInterval);//Merge the overplaing intervals and add to the list at the right position.
        return merged;
    }
