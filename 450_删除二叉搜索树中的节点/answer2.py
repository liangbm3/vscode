# Definition for a binary tree node.
# from typing import Optional
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if root is None:
            return None
        if root.val > key:
            root.left=self.deleteNode(root=root.left,key=key)
        elif root.val < key:
            root.right=self.deleteNode(root=root.right,key=key)
        else:
            if root.left is None and root.right is None:
                root=None
            elif root.left and root.right:
                aim=root.right
                while aim.left:
                    aim=aim.left
                aim.right=self.deleteNode(root=root.right,key=aim.val)
                aim.left=root.left
                root=aim
            elif root.left:
                root=root.left
            else:
                root=root.right
            return root