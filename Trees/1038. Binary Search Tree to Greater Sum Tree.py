# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

"""
Algorithm:
 - Traverse the tree in reverse in-order.
 - Maintain a cumulative sum of all visited nodes.
 - Update each node's value with the cumulative sum.
"""

# TC: O(N) where N is number of nodes in BST
# SC: O(H) where H is the height of BST
class Solution:
    def __init__(self):
        self.cummulativeSum: int = 0
      
    def bstToGst(self, root: TreeNode) -> TreeNode:
        if root is None:
            return None

        self.bstToGst(root.right)

        root.val += self.cummulativeSum
        self.cummulativeSum = root.val

        self.bstToGst(root.left)
        return root
      
