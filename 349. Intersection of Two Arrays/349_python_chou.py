class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        ans = []
        if len(nums1)>=len(nums2):
            for item in nums2:
                if item in nums1 and item not in ans:
                    ans.append(item);
        else:
            for item in nums1:
                if item in nums2 and item not in ans:
                    ans.append(item);
        return ans
