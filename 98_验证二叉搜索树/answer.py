# Definition for a binary tree node.
from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
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
        if result==[]:
            return True
        elif len(result)==1:
            return True
        else:
            for i in range(len(result)-1):
                if result[i]>=result[i+1]:
                    return False
            return True
    
if __name__ =="__main__":
    node1=TreeNode(val=3)
    node2=TreeNode(val=2)
    root=TreeNode(val=1,left=node1,right=node2)
    so=Solution()
    answer=so.balanceBST(root)
    print(answer)   