class Solution:
    def rec(self,text1,text2,i,j,dp):
        if i>=len(text1) or j>=len(text2):
            return 0
        if dp[i][j]!=-1:
            return dp[i][j]
        if text1[i]==text2[j]:
            dp[i][j]=1+(self.rec(text1,text2,i+1,j+1,dp))
        else:
            dp[i][j]=max(self.rec(text1,text2,i,j+1,dp),self.rec(text1,text2,i+1,j,dp))
        return dp[i][j]

    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m=len(text1)
        n=len(text2)
        dp=[[-1]*n for i in range(m)]
        return self.rec(text1,text2,0,0,dp)