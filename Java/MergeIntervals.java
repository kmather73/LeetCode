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
    public List<Interval> merge(List<Interval> intervals) {
        List<Interval> merged = new ArrayList<Interval>();
        if(intervals == null || intervals.size() == 0){
            return merged;
        }
        
        Collections.sort(intervals, new CustomComparator());// First sort the intervals. 
        int start = intervals.get(0).start;//keeps track of the current start position.
        int end = intervals.get(0).end;//keeps track of the current finishing position.
        
        for(Interval myInt: intervals){
            if(end < myInt.start){//The current end is before the next start.
                merged.add( new Interval(start,end));//merge the current intervals up to this point.
                start = myInt.start;//set the new starting position.
            }
            end = Math.max(end,myInt.end);// set the new ending position.
        }
        merged.add(new Interval(start,end));//don't forget to add the last interval.
        return merged;
    }
    
    //Make a new comparator to sort via the start as the primary key and end as the secondary key.
    public class CustomComparator implements Comparator<Interval> {
    @Override
        public int compare(Interval i1, Interval i2) {
            if(i1.start < i2.start){ return -1;}
            else if(i1.start > i2.start){ return 1;}
            else{ return i1.end - i2.end;}
        }
    }
}
