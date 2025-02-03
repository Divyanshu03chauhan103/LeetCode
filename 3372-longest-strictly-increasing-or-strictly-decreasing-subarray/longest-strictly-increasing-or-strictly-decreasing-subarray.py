class Solution(object):
    def longestMonotonicSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result=1
        s_dec=1
        s_inc=1

        for i in range(1,len(nums)):
            if(nums[i]>nums[i-1]):
                s_inc+=1
                s_dec=1
            elif (nums[i]<nums[i-1]):
                s_dec+=1
                s_inc=1
            else:
                s_dec=1
                s_inc=1
            result=max(result, max(s_dec,s_inc))
        return result
        