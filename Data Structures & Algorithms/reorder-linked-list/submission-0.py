# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        sec = slow.next
        slow.next = prev = None
        while sec:
            temp = sec.next
            sec.next = prev
            prev = sec
            sec = temp
        
        # now prev is beginning of the second half
        first = head
        while first and prev:
            temp = prev.next
            prev.next = first.next
            first.next = prev
            first = prev.next
            prev = temp