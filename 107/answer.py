from typing import Optional
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> list[list[int]]:
        queue=[]
        result=[]
        current=root
        if root is None:
            return result
        else:
            queue.append(root)
            while queue:
                tem=[]
                size=len(queue)
                for i in range(size): 
                    current=queue.pop(0)
                    tem.append(current.val)
                    if current.left:
                        queue.append(current.left)
                    if current.right:
                        queue.append(current.right)
                result.insert(0,tem)
            return result