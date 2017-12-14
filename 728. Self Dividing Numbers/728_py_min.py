class Solution(object):
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        ret = []
        for x in range(left , right+1):
            self_divided = True
            target = x
            while x != 0:
                d = x%10
                x = x/10
                if d == 0 or target % d != 0:
                    self_divided = False
                    break
            if self_divided == True:
                ret.append(target)
        return ret
