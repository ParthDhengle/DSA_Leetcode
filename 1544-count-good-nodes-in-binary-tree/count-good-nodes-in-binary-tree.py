# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rec(self,node,Max):
        if not node:
            return 0
        counter=0
        if node.val>=Max:
            Max=node.val
            counter+=1
        return counter + self.rec(node.left,Max) + self.rec(node.right,Max)


    def goodNodes(self, root: TreeNode) -> int:
        return self.rec(root,-1000000)