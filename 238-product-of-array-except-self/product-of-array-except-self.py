class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n=len(nums)
        ans=[1]*n

        for i in range(1,len(nums)):
            ans[i]=ans[i-1]*nums[i-1]

        print(ans)
        curr=1
        for i in range(n-1,-1,-1):
            ans[i]=ans[i]*curr
            curr*=nums[i]
        
        return ans