# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: ListNode | None) -> ListNode | None:
        if head.next is None:
            return None
        prev=ListNode(0)
        prev.next=head

        slow=head
        fast=head
        while fast and fast.next:
            fast=fast.next.next
            slow=slow.next
            prev=prev.next
        
        prev.next=slow.next
        return head