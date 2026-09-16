class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1=sorted(s1)
        i=0
        n=len(s1)
        m=len(s2)
        if(n>m):
            return False
        while i<=m-n:
            sub= sorted(s2[i:n+i])
            if s1== sub:
                return True
            i+=1
        return False