# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: ListNode | None, list2: ListNode | None) -> ListNode | None:
        
        if not list1:
            return list2

        if not list2:
            return list1

        if list1.val <= list2.val:
            list1.next=self.mergeTwoLists(list1.next,list2)
            return list1
        else:
            list2.next=self.mergeTwoLists(list1,list2.next)
            return list2
        
        return None

    def partitionAndMerge(self, s:int, e:int, lists:list[ListNode|None]):
        if s>e:
            return None
        if s==e:
            return lists[s]

        mid= s+ (e-s)//2
        l1=self.partitionAndMerge(s,mid,lists)
        l2=self.partitionAndMerge(mid+1,e,lists)

        return self.mergeTwoLists(l1,l2)
    def mergeKLists(self, lists: list[ListNode | None]) -> ListNode | None:
        return self.partitionAndMerge(0,len(lists)-1,lists)
        