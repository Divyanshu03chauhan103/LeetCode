class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n=len(height)
        left_boundary=list(range(n))
        right_boundary=list(range(n))

        for i in range(0,n):

            if(i==0):
                left_boundary[i]=height[i]
            elif left_boundary[i-1]>height[i]:
                left_boundary[i]=left_boundary[i-1]
            else:
                left_boundary[i]=height[i]
            
            if(i==0):
                right_boundary[n-i-1]=height[n-i-1]
            elif(right_boundary[n-i]>height[n-i-1]):
                right_boundary[n-i-1]=right_boundary[n-i]
            else: 
                right_boundary[n-i-1]=height[n-i-1]

        
        tw=0
        for i in range(0,n):

            tw+= min(left_boundary[i],right_boundary[i])-height[i]
        
        return tw



        