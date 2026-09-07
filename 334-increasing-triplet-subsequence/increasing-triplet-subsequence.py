class Solution:
    def lower_bound(self,x,arr):
        left,right=0,len(arr)
        while left<right:
            mid= left+(right-left)//2
            if arr[mid]>=x:
                right=mid
            else:
                left=mid+1
        return left
    def increasingTriplet(self, nums: List[int]) -> bool:
        if len(nums)<3:
            return False
        lst=[]
        for i in nums:
            lb=self.lower_bound(i,lst)
            if lb==len(lst):
                lst.append(i)
            else:
                lst[lb]=i
            if len(lst)==3:
                return True
        return False
            