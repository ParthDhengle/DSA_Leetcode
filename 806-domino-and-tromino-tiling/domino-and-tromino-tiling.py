class Solution:
    def numTilings(self, n: int) -> int:
        mod=1000000000 +7
        if n==1:
            return 1
        if n==2:
            return 2
        
        t=[0]*(n+1)
        t[1]=1
        t[2]=2
        t[3]=5
        for i in range(4,n+1):
            t[i]=((2*t[i-1])%mod + t[i-3] % mod)% mod
        return t[n]