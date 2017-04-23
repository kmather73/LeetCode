# Fails, TLE

class Solution(object):
    def nearestPalindromic(self, n):
        """
        :type n: str
        :rtype: str
        """
        m = int(n)
        b = 0
        i = 0
        
        left = m-1
        right = m+1
        while True:
            al = str(left)
            
            if al==al[::-1]:
                return str(left)
            
            ar = str(right)
            if ar == ar[::-1]:
                return str(right)
                
            left -= 1
            right += 1
            
        
        return 0
