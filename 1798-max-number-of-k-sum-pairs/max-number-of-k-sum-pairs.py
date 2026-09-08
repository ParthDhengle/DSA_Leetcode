class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        nums.sort()
        left,right=0,len(nums)-1
        count=0
        while(left<right):
            sum=nums[left]+nums[right]
            if sum==k:
                left+=1
                right-=1
                count+=1
            elif sum>k:
                right-=1
            else:
                left+=1
        return count
