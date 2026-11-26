class Solution:
    def rec(self,i,j,m,n,dp):
        if i==m-1 and j==n-1:
            return 1
        if i>=m or j>=n:
            return 0
        if dp[i][j]!=-1:
            return dp[i][j]
        dp[i][j]=self.rec(i,j+1,m,n,dp)+ self.rec(i+1,j,m,n,dp)
        return dp[i][j]
    def uniquePaths(self, m: int, n: int) -> int:
        dp=[[-1]*n for i in range(m)]
        return self.rec(0,0,m,n,dp)
