class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        sum=0
        n=len(nums)
        for i in range(k):
            sum+=nums[i]
        i=k
        print(sum)
        Max=sum/k
        while i<n:
            sum+=nums[i]
            sum-=nums[i-k]
            print(sum)
            Max=max(Max,sum/k)
            i+=1
        return Max