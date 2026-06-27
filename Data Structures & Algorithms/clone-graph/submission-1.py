"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        
        oldToNew = {}
        oldToNew[node] = Node(node.val)
        q = deque()
        q.appendleft(node)

        def bfs(node):
            while len(q) > 0:
                n = q.popleft()
                for nei in n.neighbors:
                    if nei not in oldToNew:
                        oldToNew[nei] = Node(nei.val)
                        q.append(nei)
                    oldToNew[n].neighbors.append(oldToNew[nei])
        
        bfs(node)
        return oldToNew[node]