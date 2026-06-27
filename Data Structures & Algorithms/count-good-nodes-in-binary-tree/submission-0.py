# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def traverse(r, mp):
            if not r:
                return 0
            res = 0
            if mp <= r.val:
                res += 1
            res += traverse(r.left, max(mp, r.left.val)) if r.left else 0
            res += traverse(r.right, max(mp, r.right.val)) if r.right else 0
            return res
        
        if not root:
            return 0
        return traverse(root, root.val)