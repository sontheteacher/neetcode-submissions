# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def getVal(self, node):
        if node:
            return (False, node.val)
        return (True, True) # (node is None, node is None)
    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists: return None
        lists = sorted(lists, key = self.getVal)
        res = curr = ListNode()
        while lists[0] != None:
            curr.next = lists[0]
            curr = curr.next
            lists[0] = lists[0].next
            lists = sorted(lists, key = self.getVal)
        return res.next
