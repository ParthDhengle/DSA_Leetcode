# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: ListNode | None) -> int:
        slow=head
        fast=head
        while fast and fast.next:
            fast=fast.next.next
            slow=slow.next

        prev=None
        curr=slow
        while curr:
            nxt=curr.next
            curr.next=prev
            prev=curr
            curr=nxt

        left=head
        right=prev
        M=0

        while right:
            M=max(M,left.val + right.val)
            right=right.next
            left=left.next
        return M