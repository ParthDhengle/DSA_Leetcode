class Solution:
    def pivotIndex(self, nums: list[int]) -> int:
        leftsum=0
        rightsum=sum(nums)

        for i in range(len(nums)):
            if leftsum==rightsum-nums[i]:
                return i
            leftsum+=nums[i]
            rightsum-=nums[i]
        return -1