# 2017/11/04
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxV = nums[0]
        curV = nums[0]
        
        for item in nums[1:]:
            if curV < 0 :
                curV = max(item, curV)
            else:
                curV = curV + item
            maxV = max(curV, maxV)
        return maxV
