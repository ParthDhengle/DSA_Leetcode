# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rec(self,node,sum,counter):
        if not node:
            return
        if counter>=len(sum):
            sum.append(node.val)
        else:
            sum[counter]+=node.val
        self.rec(node.left,sum,counter+1)
        self.rec(node.right,sum,counter+1)
    def maxLevelSum(self, root: TreeNode | None) -> int:
        sum=[]
        self.rec(root,sum,0)
        Max=max(sum)
        for i in range(len(sum)):
            if sum[i]>=Max:
                return i+1
        return 0