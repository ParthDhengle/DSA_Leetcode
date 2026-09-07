class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        if len(nums)<3:
            return False
        n1 = float('inf')
        n2 = float('inf')
        for i in nums:
            if n1>=i:
                n1=i
            elif n2>=i:
                n2=i
            else:
                return True
        return False