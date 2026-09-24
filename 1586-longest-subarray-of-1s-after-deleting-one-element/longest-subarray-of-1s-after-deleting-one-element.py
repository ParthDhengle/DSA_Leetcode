class Solution:
    def longestSubarray(self, nums: list[int]) -> int:
        zc=0
        l=0
        ans=0
        for i in range(len(nums)):
            if nums[i]==0:
                zc+=1
            while zc>1:
                if nums[l]==0:
                    zc-=1
                l+=1
            ans=max(ans,i-l)
        return ans