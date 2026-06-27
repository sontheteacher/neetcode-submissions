# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class NodeWrapper:
    def __init__(self, node):
        self.node = node

    def __lt__(self, other):
        return self.node.val < other.node.val

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists: return None
        
        minHeap = []
        for lst in lists:
            if lst is not None: minHeap.append(NodeWrapper(lst))
        heapq.heapify(minHeap)
        cur = res = ListNode()

        while minHeap:
            nodeWrapper = heapq.heappop(minHeap)
            cur.next = nodeWrapper.node
            cur = cur.next
            if cur.next is not None:
                heapq.heappush(minHeap, NodeWrapper(cur.next))
        
        return res.next

