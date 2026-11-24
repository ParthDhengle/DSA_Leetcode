class Solution:
    def rec(self,cost,curr,dp):
        if curr>=len(cost):
            return 0
        if dp[curr]!=-1:
            return dp[curr]
        dp[curr]=cost[curr] + min(self.rec(cost,curr+1,dp) , self.rec(cost,curr+2,dp))
        return dp[curr]
    def minCostClimbingStairs(self, cost: list[int]) -> int:
        dp=[-1]*len(cost)
        return min(self.rec(cost,0,dp) , self.rec(cost,1,dp))