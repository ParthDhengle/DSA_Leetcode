class Solution:
    def largestAltitude(self, gain: list[int]) -> int:
        height=0
        ans=0
        for i in gain:
            height+=i
            ans=max(ans,height)
        return ans