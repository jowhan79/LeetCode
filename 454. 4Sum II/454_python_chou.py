# 2017/11/20 Peony
class Solution(object):
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        AB = {}
        ans = 0
        
        for a in A:
            for b in B:
                ab = a+b
                if ab in AB:
                    AB[ab] += 1
                else:
                    AB[ab] = 1
          
        for c in C:
            for d in D:
                cd = -(c+d)
                if cd in AB:
                    ans += AB[cd]
        
        return ans
