class Solution:
    def findDifference(self, nums1: list[int], nums2: list[int]) -> list[list[int]]:
        s1=set(nums1)
        s2=set(nums2)
        right=[]
        left=[]
        for i in s2:
            if i not in s1:
                right.append(i)

        for i in s1:
            if i not in s2:
                left.append(i)

        return [left,right]