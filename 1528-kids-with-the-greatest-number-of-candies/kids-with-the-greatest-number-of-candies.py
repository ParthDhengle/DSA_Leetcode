class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        M=max(candies)
        lst=[]
        for i in candies:
            lst.append(i+extraCandies >= M)
        return lst