class Solution:
    def rob(self, nums: list[int]) -> int:
        n=len(nums)
        if not n:
            return 0
        if n==1:
            return nums[0]
        if n==2:
            return max(nums[0],nums[1])
        
        nums[n-3]=nums[n-3]+nums[n-1]
        for i in range(n-4,-1,-1):
            nums[i]=nums[i]+ max(nums[i+2], nums[i+3])
        return max(nums[0],nums[1])