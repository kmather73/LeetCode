class Solution(object):
    def repeatedSubstringPattern(self, str):
        """
        :type str: str
        :rtype: bool
        """
        n = len(str)
        for i in range(1, n/2 + 1):
            s = str[:i]

            if s*(n/i) == str:
                return True
                
        return False
