class Solution:
    def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:
        if root is None:
            return None

        if root.left is None and root.right is None:
            if root.val == target:
                del root
                return None
            else:
                return root

        root.left = self.removeLeafNodes(root.left, target)
        root.right = self.removeLeafNodes(root.right, target)

        if root.left is None and root.right is None:
            if target == root.val:
                del root
                return None

        return root
