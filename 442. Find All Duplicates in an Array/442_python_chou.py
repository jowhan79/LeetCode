# 2017/11/14 Peony
class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums.sort()
        ans=[]
        for i, j in zip(nums[:-1], nums[1:]):
            if(i==j):
                ans.append(i)
        return ans
