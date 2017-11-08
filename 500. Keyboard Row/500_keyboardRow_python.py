# 2017/11/02 Peony
class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        result = []
        tableList = {0:"qwertyuiop", 1:"asdfghjkl", 2:"zxcvbnm"}
        
        for i in words:
            t = []
            for ch in i:
                if ch.lower() in tableList[0]:
                    t.append(0)
                elif ch.lower() in tableList[1]:
                    t.append(1)
                elif ch.lower() in tableList[2]:
                    t.append(2)
            if len(set(t)) == 1:
                result.append(i)
                    
        
        return result
