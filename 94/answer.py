# Definition for a binary tree node.
from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> list[int]:
        stack=[]
        result=[]
        current=root
        while current or stack:
            while current:                                                                                   
                stack.append(current)
                current=current.left
            current=stack.pop()
            result.append(current.val)
            current=current.right
        return result
            
            
if __name__ =="__main__":
    node1=TreeNode(val=3)
    node2=TreeNode(val=2)
    root=TreeNode(val=1,left=node1,right=node2)
    so=Solution()
    answer=so.inorderTraversal(root)
    print(answer)          
        