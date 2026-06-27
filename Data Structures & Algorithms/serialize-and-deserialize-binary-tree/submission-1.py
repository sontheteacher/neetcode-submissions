# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Codec:
    
    # Encodes a tree to a single string.
    def serialize(self, root: Optional[TreeNode]) -> str:
        if not root: return ""
        res = []
        q = deque()
        q.append(root)
        while q:
            curr = q.popleft()
            if curr:
                res.append(str(curr.val))
                q.append(curr.left)
                q.append(curr.right)
            else:
                res.append('#')
        return ",".join(res)
        
    # Decodes your encoded data to tree.
    def deserialize(self, data: str) -> Optional[TreeNode]:
        if not data: return None
        
        data = data.split(",")

        root = TreeNode(data[0])
        q = deque()
        q.append(root)
        i = 1
        while q and i < len(data):
            curr = q.popleft()
            if curr is None: continue
            if data[i] != '#':
                curr.left = TreeNode(data[i])
                q.append(curr.left)
            else:
                curr.left = None
            
            if data[i + 1] != '#':
                curr.right = TreeNode(data[i + 1])
                q.append(curr.right)
            else:
                curr.right = None
            i += 2
        return root