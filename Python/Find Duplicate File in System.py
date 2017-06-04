from collections import defaultdict
class Solution:
    def findDuplicate(self, paths):
        """
        :type paths: List[str]
        :rtype: List[List[str]]
        """
        
        files = defaultdict(list)
        dups = list()
        
        for path in paths:
            names = path.split(" ")
            
            tp = names[0]
            
            for i in range(1, len(names)):
                cont = names[i].split("(")
                key = cont[1]
                files[key].append(tp+"/"+cont[0])
                    
        
        for k in files:
            
            if len(files[k]) > 1:
                dups.append(files[k])
                
        return dups
