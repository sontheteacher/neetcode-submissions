# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        res = 0
        def dfs(root):
            nonlocal res
            if not root:
                return (-2000, -2000)
            if not (root.left or root.right): 
                return (root.val, root.val)
            left = dfs(root.left)
            right = dfs(root.right)
            max_end_root = root.val + max(left[0], right[0], 0)
            tree_max = max(left[1], right[1], max_end_root, root.val + left[0] + right[0])
            res = max(res, tree_max)
            return (max_end_root, tree_max)
        return dfs(root)[1]