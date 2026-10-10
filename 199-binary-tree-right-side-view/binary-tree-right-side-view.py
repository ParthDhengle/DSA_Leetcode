# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    Max=-1
    def rec(self,node,counter,lst):
        if not node:
            return
        if counter>self.Max:
            lst.append(node.val)
            self.Max=counter
        self.rec(node.right,counter+1,lst)
        self.rec(node.left,counter+1,lst)

    def rightSideView(self, root: TreeNode | None) -> list[int]:
        lst=[]
        self.rec(root,0,lst)
        return lst