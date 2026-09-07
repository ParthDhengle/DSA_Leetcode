class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        k1,k2=0,0
        n1,n2=len(s),len(t)
        while k1<n1 and k2<n2:
            if s[k1]==t[k2]:
                k1+=1
            k2+=1
        return k1==n1