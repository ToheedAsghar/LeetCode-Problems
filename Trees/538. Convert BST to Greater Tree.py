# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Same as https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/

class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return None
        
        cummulativeSum: int = 0

        def convertBSTHelper(root: Optional[TreeNode]) -> Optional[TreeNode]:
            if root is None:
                return None
            
            nonlocal cummulativeSum

            convertBSTHelper(root.right)
            cummulativeSum += root.val
            root.val = cummulativeSum
            convertBSTHelper(root.left)

            return root
        
        return convertBSTHelper(root)
