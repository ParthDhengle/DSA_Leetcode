class Solution:
    def rec(self, prices, fee, i, sell,dp):
        if i>=len(prices):
            return 0
        if sell:
            if dp[1][i]!= -1:
                return dp[1][i]
            s=(prices[i]-fee)+self.rec(prices,fee,i+1,False,dp)
            ns=(self.rec(prices,fee,i+1,True,dp))
            dp[1][i]=max(s,ns)
            return dp[1][i]
        else:
            if dp[0][i]!=-1:
                return dp[0][i]
            b=self.rec(prices,fee,i+1,True,dp) - prices[i]
            nb=self.rec(prices,fee,i+1,False,dp)
            dp[0][i]=max(b,nb)
            return dp[0][i]
        
    def maxProfit(self, prices: list[int], fee: int) -> int:
        dp=[[-1]*len(prices) for i in range(2)]
        return self.rec(prices,fee,0,False,dp)