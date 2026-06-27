# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        f1, f2 = l1, l2
        carry = 0
        prev = None
        while f1 and f2:
            s = f1.val + f2.val + carry
            carry = s // 10
            s %= 10
            f1.val = f2.val = s
            prev = f1 if f1 else f2
            f1 = f1.next
            f2 = f2.next
        head = None
        if f1:
            head = l1
            while f1 and carry:
                s = f1.val + carry
                carry = s // 10
                s %= 10
                f1.val = s
                prev = f1
                f1 = f1.next
            if carry:
                prev.next = ListNode(1)
        elif f2:
            head = l2
            while f2 and carry:
                s = f2.val + carry
                carry = s // 10
                s %= 10
                f2.val = s
                prev = f2
                f2 = f2.next
            if carry:
                prev.next = ListNode(1)
        else:
            head = l1
            if carry:
                prev.next = ListNode(carry)
        return head

        