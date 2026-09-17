class Solution:
    def longestOnes(self, nums: list[int], k: int) -> int:
        ans=0
        zc=0
        l=0
        n=len(nums)
        for i in range(n):
            if nums[i]==0:
                zc+=1
            while(zc>k):
                if nums[l]==0:
                    zc-=1
                l+=1
            ans=max(ans, i-l+1)

        return ans
                    
            
