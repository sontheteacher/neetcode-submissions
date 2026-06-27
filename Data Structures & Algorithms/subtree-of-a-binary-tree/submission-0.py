# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def compare_directly(self, root, subRoot):
        if not root and not subRoot: return True
        if root and subRoot and root.val == subRoot.val:
            return self.compare_directly(root.left, subRoot.left) and self.compare_directly(root.right, subRoot.right)
        return False

    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        
        if not subRoot: return True
        if not root: return False

        # compare tree root subroot
        if self.compare_directly(root, subRoot): return True
        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)