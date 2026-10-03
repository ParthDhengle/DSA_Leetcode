# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rec(self,node, lst,target):
        if not node:
            return 0
        counter=0
        new_lst=lst.copy()
        for i in range(len(new_lst)):
            new_lst[i]+=node.val
            if new_lst[i]==target:
                counter+=1
        if node.val==target:
            counter+=1
        new_lst.append(node.val)

        left=self.rec(node.left, new_lst, target) 
        right=self.rec(node.right, new_lst, target)

        return counter + left + right

    def pathSum(self, root: TreeNode | None, targetSum: int) -> int:
        lst=[]
        counter=0
        return self.rec(root, lst, targetSum)
        
        