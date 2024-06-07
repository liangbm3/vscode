# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        stack=[]
        arr=[]
        current=root
        while current or stack:
            while current:
                stack.append(current)
                current=current.left
            current=stack.pop()
            arr.append(current.val)
            current=current.right
        new_tree=self.build_tree(tree_arr=arr)
        return new_tree
    def build_tree(self,tree_arr:list):
        new_tree=TreeNode()
        arr_length=len(tree_arr)
        mid=arr_length//2
        new_tree.val=tree_arr[mid]
        if mid-1>=0:
            new_tree.left=self.build_tree(tree_arr=tree_arr[0:mid])
        if mid+1<arr_length:
            new_tree.right=self.build_tree(tree_arr=tree_arr[mid+1:arr_length+1])
        return new_tree    
        
        
        
if __name__ =="__main__":
    node1=TreeNode(val=3)
    node2=TreeNode(val=2)
    root=TreeNode(val=1,left=node1,right=node2)
    so=Solution()
    answer=so.balanceBST(root)
    print(answer)   