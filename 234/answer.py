# Definition for singly-linked list.
from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        cur=head
        stack=[]
        stack.append(cur.val)
        while cur.next is not None:
            if cur.next.val==stack[-1]:
                stack.pop()
            else:
                stack.append(cur.next.val)
            cur=cur.next
        if not stack:
            return True
if __name__=="__main__":
    answer=Solution()
    a6=ListNode(val=1,next=None)
    a5=ListNode(val=2,next=a6)
    a4=ListNode(val=9,next=a5)
    a3=ListNode(val=9,next=a4)
    a2=ListNode(val=2,next=a3)
    a1=ListNode(val=1,next=a2)
    head=a1
    res=answer.isPalindrome(head)
    print(res)