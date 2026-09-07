class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k=0
        count=0
        for i in nums:
            if i==0:
                count+=1
            else:
                nums[k]=i
                k+=1
        for i in range(count):
            nums[k]=0
            k+=1
        