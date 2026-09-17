class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vc=0
        vov=['a','e','i','o','u']
        for i in range(k):
            if s[i] in vov:
                vc+=1
        n=len(s)
        Max=0
        for i in range(k,n):
            Max=max(Max,vc)
            if s[i] in vov:
                vc+=1
            if s[i-k] in vov:
                vc-=1
        Max=max(Max,vc)
        return Max
