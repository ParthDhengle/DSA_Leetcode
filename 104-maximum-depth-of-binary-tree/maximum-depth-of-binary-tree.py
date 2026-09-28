# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rec(self, node, curr):
        if not node:
            return curr
        return max(self.rec(node.left,curr+1) , self.rec(node.right,curr+1))
    def maxDepth(self, root: TreeNode | None) -> int:
        return self.rec(root,0)
        