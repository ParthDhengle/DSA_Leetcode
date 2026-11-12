class Solution:
    def rec(self,k,n,curr,ans,lst):
        if len(lst)==k:
            if n==0:
                ans.append(lst.copy())
            return
        for i in range(curr,10):
            if i>n:
                break
            lst.append(i)
            self.rec(k,n-i,i+1,ans,lst)
            lst.pop()

    def combinationSum3(self, k: int, n: int) -> list[list[int]]:
        ans=[]
        self.rec(k,n,1,ans,[])
        return ans
