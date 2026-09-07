class Solution:
    def lower_bound(self, x,nums):
        left,right=0,len(nums)
        while left<right:
            mid=left+(right-left)//2
            if nums[mid]>=x:
                right=mid
            else:
                left=mid+1
        return left
        
    def lengthOfLIS(self, nums: List[int]) -> int:
        lst=[]
        for i in nums:
            lb= self.lower_bound(i,lst)
            if lb==len(lst):
                lst.append(i)
            else:
                lst[lb]=i
        return len(lst)