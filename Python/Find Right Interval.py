# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def findRightInterval(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[int]
        """
        
        l = [];
        for i in range(len(intervals)):
            x = intervals[i]
            l.append( (x.start, i) )
        l = sorted(l, key=lambda x: x[0])
        
        ans = []
        n = len(l)
        for i in intervals:
            k = bisect.bisect_left(l, (i.end, 0))
            if k < n:
                ans.append(l[k][1])
            else:
                ans.append(-1)
            
        return ans
        
