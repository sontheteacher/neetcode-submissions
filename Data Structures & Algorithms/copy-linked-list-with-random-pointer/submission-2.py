"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return head
        mapp = {}
        curr = head
        cp = Node(curr.val)
        mapp[head] = cp
        while curr:
            cp = mapp[curr]
            if curr.next:
                cp_nxt = Node(x = curr.next.val) if mapp.get(curr.next) is None else mapp.get(curr.next)
                mapp[curr.next] = cp_nxt
                cp.next = cp_nxt
            if curr.random:
                cp_rand = Node(x = curr.random.val) if mapp.get(curr.random) is None else mapp.get(curr.random)
                mapp[curr.random] = cp_rand
                cp.random = cp_rand
            curr = curr.next
        return mapp[head]
