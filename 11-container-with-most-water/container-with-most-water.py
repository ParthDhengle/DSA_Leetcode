class Solution:
    def maxArea(self, height: List[int]) -> int:
        Max=0
        left,right=0,len(height)-1
        while(left<right):
            if height[left]<height[right]:
                Max=max(Max,(right-left)*height[left])
                left+=1
            else:
                Max=max(Max,(right-left)*height[right])
                right-=1
        return Max