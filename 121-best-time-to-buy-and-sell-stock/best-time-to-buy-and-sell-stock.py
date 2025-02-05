class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        profit=0

        buy=prices[0]
        for i in range(1,len(prices)):
            if prices[i]<buy:
                buy=prices[i]
            else:
                profit=max(profit,prices[i]-buy)
        return profit
        