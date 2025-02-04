class Solution(object):
    def maxAscendingSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result=nums[0]
        
        temp_Sum=nums[0]

        for i in range(1,len(nums)):
            if(nums[i]>nums[i-1]):
                temp_Sum+=nums[i]
            else:
                temp_Sum=nums[i]
            result=max(temp_Sum,result)
        return result
        