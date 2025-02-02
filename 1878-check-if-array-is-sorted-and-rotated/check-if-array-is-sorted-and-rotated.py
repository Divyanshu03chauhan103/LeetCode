class Solution(object):
    def check(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums)
        count=0
        if(nums[0]<nums[n-1]):
            count=count+1
        for i in range(1,n):
               if(nums[i]<nums[i-1]):
                    count=count+1    
        return False if count>1 else True