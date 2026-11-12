class Solution:
    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        Min=1
        Max=max(piles)
        while Min<=Max:
            mid=(Max-Min)//2 + Min
            hours=0
            for i in piles:
                hours+=(i+mid-1)//mid
            if hours<=h:
                Max=mid-1
            else:
                Min=mid+1

        return Min