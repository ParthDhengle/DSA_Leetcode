# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deletion(self,node,key):
        if not node.right:
            return node.left
        if not node.left:
            return node.right
        curr=node.left
        while curr.right:
            curr=curr.right
        curr.right=node.right.left
        node.right.left=node.left
        return node.right
    def deleteNode(self, node: TreeNode | None, key: int) -> TreeNode | None:
        if not node:
            return node
        
        if node.val==key:
            return self.deletion(node,key)
        
        if node.val>key:
            node.left=self.deleteNode(node.left,key)
        if node.val<key:
            node.right=self.deleteNode(node.right,key)
        return node