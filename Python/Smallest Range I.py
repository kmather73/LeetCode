class Solution:
    def smallestRangeI(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        a = min(A)
        b = max(A)
        
        if b - a <= 2*K:
            return 0
        else:
            return b - a -2*K
