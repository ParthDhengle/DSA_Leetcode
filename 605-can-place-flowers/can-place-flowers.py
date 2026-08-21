class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        i=0
        while n>0 and i<len(flowerbed):
            if flowerbed[i]==1:
                i+=1
                continue
            if (i>0 and flowerbed[i-1]==1 ) or (i<len(flowerbed)-1 and flowerbed[i+1]==1):
                i+=1
                continue
            flowerbed[i]=1
            n-=1
            i+=1
        return n==0