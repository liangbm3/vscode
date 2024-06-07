# Definition for a binary tree node.
from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        self.search(root)
        self.key=key
    def search(self,tree):
        if tree:
            if self.key==tree.val:
                self.node_delete(node=tree)
            self.search(tree=tree.left)
            self.search(tree=tree.right)
    def node_delete(self,node:Optional[TreeNode]):
        if node.left and node.right:
            tree=node.left
            new_tree=self.search_mid(tree=tree)
            node.val=new_tree.val
    def delete(self,tree):
        if tree.left.left is None:
            tree
    def search_mid(self,tree):
        if tree:
            self.search_mid(tree=tree.left)
            return tree
            
            