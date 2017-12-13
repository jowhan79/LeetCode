class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        ret = s.split(" ")
        ret[0] = ret[0][::-1]
        return reduce(lambda x , y: x+" "+y[::-1] ,ret)
